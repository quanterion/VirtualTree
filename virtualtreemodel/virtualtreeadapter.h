#ifndef VIRTUALMODELADAPTER_H
#define VIRTUALMODELADAPTER_H

#include "QVariant"

class VirtualModelInterface;

class VirtualModelAdapter {
public:
  virtual int getItemsCount(void *parent) = 0;
  virtual void * getItem(void *parent, int index) = 0;
  virtual QVariant data(void *item, int role) = 0;

  // reimplement if you can optimize them
  virtual int indexOf(void *parent, void *item, int start = 0);
  virtual bool hasItems(void *parent);
  // needed to map item to QIndex by VirtualTreeModel::getItemIndex only
  virtual void * getItemParent(void *item);

  void beginUpdate();
  void endUpdate();
  void QueuedUpdate();

  void setModel(VirtualModelInterface *intf) { m_modelIntf = intf; }
  VirtualModelInterface * getModel() { return m_modelIntf; }
private:
  VirtualModelInterface *m_modelIntf;
};

// link to VirtualTreeModel
class VirtualModelInterface
{
public:
    virtual void beginUpdate() = 0;
    virtual void endUpdate() = 0;
    virtual void QueuedUpdate() = 0;
};

#endif // VIRTUALMODELADAPTER_H

