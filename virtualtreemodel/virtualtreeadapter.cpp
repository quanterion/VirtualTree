#include "virtualtreeadapter.h"

int VirtualModelAdapter::indexOf(void *parent, void *item, int start)
{
  int count = getItemsCount(parent);
  for (int i = start; i < count; ++i)
    if (getItem(parent, i) == item)
      return i;
  return -1;
}

bool VirtualModelAdapter::hasItems(void *parent)
{
  return getItemsCount(parent) > 0;
}

void *VirtualModelAdapter::getItemParent(void *item)
{
  return item;
}

void VirtualModelAdapter::beginUpdate()
{
  if (m_modelIntf)
    m_modelIntf->beginUpdate();
}

void VirtualModelAdapter::endUpdate()
{
  if (m_modelIntf)
    m_modelIntf->endUpdate();
}

void VirtualModelAdapter::QueuedUpdate()
{
  if (m_modelIntf)
    m_modelIntf->QueuedUpdate();
}


VirtualModelInterface::~VirtualModelInterface()
{

}
