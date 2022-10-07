# BLE Gateway Device Management (DM) Firmware

This firmware acts as a BLE gateway that bridges BLE end nodes to the cloud.
The BLE gateway and the BLE end nodes can be managed via LwM2M.

[Version History](version_history)

## Boards supported by this firmware

- mg100
- pinnacle_100_dvk
- bl5340_dvk_cpuapp

## Generating the API

The API is automatically generated as part of the build, but it can also be generated manually.
[app.yml](app.yml) is the base input file to generate the API (methods and attributes) for the app and all of its components.

To update the API manually if changes are made, use the following command to regenerate code.

**NOTE:** replace `{project}` in the following commands with:

- mg100_none - Pinnacle 100 DVK/MG100 device management without a telemetry connection
- mg100_lwm2m - Pinnacle 100 DVK/MG100 device management with a LwM2M telemetry connection
- mg100_mqtt - Pinnacle 100 DVK/MG100 device management with an MQTT telemetry connection
- bl5340_none - BL5340 DVK device management without a telemetry connection
- bl5340_lwm2m - BL5340 DVK device management with a LwM2M telemetry connection
- bl5340_mqtt - BL5340 DVK device management with an MQTT telemetry connection

```
# From the ble_gateway_dm_firmware directory

# Linux and macOS
python3 ../modules/lib/laird_connect/attributes/generator/api.py ${PWD} {project}

# Windows
python3 ../modules/lib/laird_connect/attributes/generator/api.py %CD% {project}
```
