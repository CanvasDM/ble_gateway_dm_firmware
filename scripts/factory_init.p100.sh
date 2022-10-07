#!/zsh

# Setup DM connection basics
attr set lwm2m_server_url coaps://lwm2m-bootstrap.edgeiq.io:5684
attr set lwm2m_security 0
attr set lwm2m_bootstrap 1

# Set the device to generate a random connection backoff on next boot
attr set dm_cnx_delay 0

# Generate private keys
pki keygen dm
pki keygen tel
pki keygen p2p
pki keygen fs

# LTE modem setup
# Clear the APN to let SIM cards do the work of attaching to the network
attr set lte_apn ""
# Set a global band config to cover all regions and reduce SKUs
attr set lte_bands 0000000000000809181F