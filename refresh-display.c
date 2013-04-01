#include <IOKit/graphics/IOGraphicsLib.h>
#include <ApplicationServices/ApplicationServices.h>

enum {
    kIOFBSetTransform = 0x00000400,
};

int main() {
	
	CGDirectDisplayID mainDisplay = CGMainDisplayID();
	
	io_service_t service = CGDisplayIOServicePort(mainDisplay);
	
	IOServiceRequestProbe(service, (kIOFBSetTransform | (kIOScaleRotate90 << 16)));
	IOServiceRequestProbe(service, (kIOFBSetTransform | (kIOScaleRotate0 << 16)));
	
	return 0;
}