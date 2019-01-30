////////////////////////////////////////////////////////////////
///
///Class:               Setup
///Description:
///           

#ifndef HS_FIT_SETUP_h
#define HS_FIT_SETUP_h

namespace HS{
  namespace FIT{
  
    class Setup  {
      
    public:
      Setup()=default;
      Setup(const Setup&)=default;
      Setup(Setup&&)=default;
      virtual ~Setup()=default;
      Setup& operator=(const Setup& other)=default;
      Setup& operator=(Setup&& other) = default;
      
    protected:
      
    private:
      
    };
    
  }//namespace FIT
}//namespace HS

#endif
