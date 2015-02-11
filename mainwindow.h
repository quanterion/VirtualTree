#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <memory>
#include <vector>

#include <QMainWindow>
#include "virtualtreemodel/virtualtreemodel.h"

class Part {
public:
    Part(): parent(nullptr) {}
    Part(const Part &other) = delete;
    Part(Part *parent, const QString &name): parent(parent), name(name) {}
    Part *parent;
    QString name;
    std::vector<std::unique_ptr<Part>> subParts;

    Part *add(const QString &name)
    {
        auto part = new Part(this, name);
        subParts.emplace_back(part);
        return part;
    }

    void remove(Part *part)
    {
        auto it = std::find_if( subParts.begin(), subParts.end(),
          [&](std::unique_ptr<Part>& p) { return p.get() == part;} );
        subParts.erase(it);
    }
};

namespace Ui {
class MainWindow;
}

class VirtualPartAdapter: public VirtualModelAdapter
{
public:
    VirtualPartAdapter(Part &root);
    int getItemsCount(void *parent) override;
    void * getItem(void *parent, int index) override;
    QVariant data(void *item, int role) override;
    void * getItemParent(void *item) override;
    Part *getValue(void * data);
private:    
    Part &m_root;
};


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionAdd_group1_triggered();

    void on_actionRemove_current_triggered();

private:
    Ui::MainWindow *ui;
    Part root;
    std::unique_ptr<VirtualPartAdapter> m_adapter;
    std::unique_ptr<VirtualTreeModel> m_treeModel;

    Part *currentPart();
};

#endif // MAINWINDOW_H
