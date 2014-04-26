''' test.py - test script for the PyPRUSS library with the PRU'''

import pypruss

pypruss.modprobe() 			  				       	# This only has to be called once pr boot
pypruss.init()										# Init the PRU
pypruss.open(0)										# Open PRU event 0 which is PRU0_ARM_INTERRUPT
pypruss.pruintc_init()								# Init the interrupt controller
pypruss.exec_program(0, "./text.bin")			# Load firmware "text.bin" on PRU 0

# Optional commands if you would like to disable the PRU
#pypruss.wait_for_event(0)							# Wait for event 0 which is connected to PRU0_ARM_INTERRUPT
#pypruss.clear_event(0)								# Clear the event
#pypruss.pru_disable(0)								# Disable PRU 0, this is already done by the firmware
#pypruss.exit()										# Exit, don't know what this does. 
