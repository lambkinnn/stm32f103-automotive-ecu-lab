Import("env")

# Match PlatformIO's hla_swd transport to OpenOCD's HLA driver.
arguments = env.BoardConfig().get("debug.tools.stlink.server.arguments")
if "transport select hla_swd" in arguments and "interface/stlink.cfg" in arguments:
    arguments[arguments.index("interface/stlink.cfg")] = "interface/stlink-hla.cfg"
