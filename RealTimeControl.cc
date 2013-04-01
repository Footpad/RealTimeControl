#include <cstdlib>
#include <iostream>
#include <stdint.h>
#include <hw/inout.h>
#include <sys/neutrino.h>
#include <sys/mman.h>
#include <stdlib.h>

#include "UserInput.h"
#include "PlantContext.h"
#include "PlantController.h"
#include "ADSensor.h"
#include "DACActuator.h"

#define BASE_ADDRESS	(0x280)
#define AD_LSB 			(BASE_ADDRESS + 0)
#define AD_MSB 			(BASE_ADDRESS + 1)
#define AD_GAIN_STATUS	(BASE_ADDRESS + 3)
#define DAC_LSB			(BASE_ADDRESS + 6)
#define DAC_MSB			(BASE_ADDRESS + 7)

#define AD_GAIN_SETTING	(0b00000000)

#define PORT_LENGTH (1)

void obtainHandle(uintptr_t* handleRef, int addr) {
	*handleRef = mmap_device_io(PORT_LENGTH, BASE_ADDRESS);
	if(*handleRef == MAP_DEVICE_FAILED) {
		std::cerr << "Failed to obtain hardware handle" << std::endl;
		exit(-1);
	}
}

int main(int argc, char *argv[]) {

	if (ThreadCtl(_NTO_TCTL_IO, NULL) != -1) {
		std::cerr << "Failed to get root permissions" << std::endl;
		return 1;
	}

	uintptr_t ctrl_handle, ad_ctrl_handle, in_msb_handle, in_lsb_handle, out_msb_handle, out_lsb_handle;

	obtainHandle(&ctrl_handle, BASE_ADDRESS);
	obtainHandle(&ad_ctrl_handle, BASE_ADDRESS);
	obtainHandle(&in_msb_handle, AD_MSB);
	obtainHandle(&in_lsb_handle, AD_LSB);
	obtainHandle(&out_msb_handle, DAC_MSB);
	obtainHandle(&out_lsb_handle, DAC_LSB);

	// TODO: configure that setting.
	out8(ad_ctrl_handle, AD_GAIN_SETTING);

	Sensor *sensor = new ADSensor(ctrl_handle, ad_ctrl_handle, in_msb_handle, in_lsb_handle);
	Actuator *actuator = new DACActuator(ctrl_handle, out_msb_handle, out_lsb_handle);

	PlantContext context;
	PlantController controller(sensor, actuator);
	UserInput input(&context);

	// Wait for user to cancel controller.
	input.start();
	input.join();

	// Clean up.
	delete sensor;
	delete actuator;

	return EXIT_SUCCESS;
}
