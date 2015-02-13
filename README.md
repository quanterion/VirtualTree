# VirtualTree
Simple wrapper for QAbstractItemModel

If you need to display hierarchical data in your Qt app you can instead of implementing QAbstractItemModel simply write VirtualModelAdapter like this instead of writing error prone index() and parent() functions

class VirtualModelAdapter {
public:
  virtual int getItemsCount(void *parent) = 0;
  virtual void * getItem(void *parent, int index) = 0;
}

after that all you need is to call adapter.QueuedUpdate() before changing your data structure and adapter automatically updates tree calling beginInsertRows() / endInsertRows() and beginRemoveRows() / endRemoveRows() with appropriate indexes
