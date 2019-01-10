
#ifndef HS_TOPOACTIONMANAGER_h
#define HS_TOPOACTIONMANAGER_h

#include <vector>
#include <memory>

namespace HS{

  using TopoIndex = UInt_t;

  class TopoActionManager{
    public:
    ///Must give an output directory for saving trees to
    TopoActionManager()=default;
    virtual ~TopoActionManager()=default;
 
    virtual Bool_t Execute(TopoIndex ti)=0;
    virtual void End(){};

  };// TopoActionManager

  using topoActMan_uptr = std::unique_ptr<TopoActionManager>;
  using topoActMan_ptr = std::shared_ptr<TopoActionManager>;
  using topoActMans =std::vector<topoActMan_ptr>;
  
};//namespace HS

#endif

