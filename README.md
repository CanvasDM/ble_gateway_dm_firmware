# BLE Gateway Device Management (DM) Firmware

This firmware acts as a BLE gateway that bridges BLE end nodes to the cloud.
The BLE gateway and the BLE end nodes can be managed via LwM2M.

## Boards supported by this firmware

- mg100
- pinnacle_100_dvk
- bl5340_dvk_cpuapp
- qemu_cortex_m3

## Generating attributes

[app.yml](app.yml) is the base input file to generate all attributes for the app and all of its components.

When updating attributes use the following command to regenerate code:

```
# From the ble_gateway_dm_firmware directory

# Linux and macOS
python3 ../modules/lib/laird_connect/attributes/generator/attribute_generator.py ${PWD}

# Windows
python3 ../modules/lib/laird_connect/attributes/generator/attribute_generator.py %CD%
```
