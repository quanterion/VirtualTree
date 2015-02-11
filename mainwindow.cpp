#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    auto g1 = root.add("Simple types");
    g1->add("bool");
    g1->add("int");
    g1->add("float");
    g1->add("double");
    auto g2 = root.add("Structured types");
    auto g3 = g2->add("Array");
    g3->add("Static");
    g3->add("Dynamic");
    g2->add("Class");

    m_adapter.reset(new VirtualPartAdapter(root));
    m_treeModel.reset(new VirtualTreeModel(m_adapter.get()));
    ui->treeView->setModel(m_treeModel.get());
}

MainWindow::~MainWindow()
{
    ui->treeView->setModel(nullptr);
    delete ui;
}

VirtualPartAdapter::VirtualPartAdapter(Part &root): m_root(root)
{

}

QVariant VirtualPartAdapter::data(void *item, int role)
{
    auto value = getValue(item);
    if (role == Qt::DisplayRole)
    {
        return value->name;
    }
    else
    {
        return QVariant();
    }
}

void *VirtualPartAdapter::getItemParent(void *item)
{
    return item ? reinterpret_cast<Part*>(item)->parent: nullptr;
}

void *VirtualPartAdapter::getItem(void *parent, int index)
{
    return getValue(parent)->subParts[index].get();
}

Part * VirtualPartAdapter::getValue(void * data)
{
    return data ? reinterpret_cast<Part*>(data): &m_root;
}

int VirtualPartAdapter::getItemsCount(void *parent)
{
    return static_cast<int>(getValue(parent)->subParts.size());
}

void MainWindow::on_actionAdd_group1_triggered()
{
    m_adapter->beginUpdate();
    Part* cur = currentPart();
    cur = cur ? cur : &root;
    auto g1 = cur->add("NewType");
    g1->add("my class");
    g1->add("my struct");
    m_adapter->endUpdate();

    ui->treeView->setCurrentIndex(m_treeModel->getItemIndex(g1));
}

void MainWindow::on_actionRemove_current_triggered()
{
    Part *part =  currentPart();
    if (part && part != &root)
    {
        m_treeModel->QueuedUpdate();
        part->parent->remove(part);
    }
}

Part *MainWindow::currentPart()
{
    return m_adapter->getValue(m_treeModel->getItem(ui->treeView->currentIndex()));
}
