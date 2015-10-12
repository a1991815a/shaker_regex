#ifndef __SHAKER_DEFINE__
#define __SHAKER_DEFINE__

#define SHAKER_NS_START namespace shaker{
#define SHAKER_NS_END	}
#define USING_NS_SHAKER using namespace shaker

#define SHAKER_SAFE_DELETE(p) do{if(p) delete p; p = nullptr;} while(0)


#endif