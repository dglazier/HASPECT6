
#ifndef HS_TOPOACTIONMANAGER_h
#define HS_TOPOACTIONMANAGER_h


namespace HS{

  using TopoIndex = UInt_t;

  class TopoActionManager{
    public:
    ///Must give an output directory for saving trees to
    TopoActionManager()=default;
    virtual ~TopoActionManager()=default;
 
    virtual Bool_t Execute(TopoIndex ti)=0;

  };// TopoActionManager
};//namespace HS

#endif

