BIOS.protocol.beginModule("AJS37", 0x4600)
BIOS.protocol.setExportModuleAircrafts({"AJS37"})

local inputProcessors = moduleBeingDefined.inputProcessors
local documentation = moduleBeingDefined.documentation
local document = BIOS.util.document  
local parse_indication = BIOS.util.parse_indication
local defineFloat = BIOS.util.defineFloat
local defineIndicatorLight = BIOS.util.defineIndicatorLight
local definePushButton = BIOS.util.definePushButton
local definePotentiometer = BIOS.util.definePotentiometer
local defineRotary = BIOS.util.defineRotary
local defineSetCommandTumb = BIOS.util.defineSetCommandTumb
local defineTumb = BIOS.util.defineTumb
local defineToggleSwitch = BIOS.util.defineToggleSwitch
local defineToggleSwitchToggleOnly = BIOS.util.defineToggleSwitchToggleOnly
local defineFixedStepTumb = BIOS.util.defineFixedStepTumb
local defineFixedStepInput = BIOS.util.defineFixedStepInput
local defineVariableStepTumb = BIOS.util.defineVariableStepTumb
local defineString = BIOS.util.defineString
local defineRockerSwitch = BIOS.util.defineRockerSwitch
local defineMultipositionSwitch = BIOS.util.defineMultipositionSwitch
local defineIntegerFromGetter = BIOS.util.defineIntegerFromGetter
local defineStartSolenoid = BIOS.util.defineElectricallyHeldSwitch
--Paneler:
--VänsterPanel
--Indikeringstablå
--Manöverpanel FR22
--Startpanel
--Radarpanel
--Manöverpanel FR24
--Testpanel
--Trimpanel
--Belysningspanel
--CentralIndikator
--Reservinstrument
--HögerPanel
--Datapanel
--Manöverpanel KA
--Manöverpanel KB
--Manöverpanel Ytterbelysning
--Manöverpanel IK
--Manöverpanel FK
--Manöverpanel SSR
--Säkringspanel
--Motorpanel

---------------------------------------------------------------------------------
-- EBK indkatorlampor by outbaxx
---------------------------------------------------------------------------------
local function defineIndicatorLightEBK1(msg, arg_number, category, description)
	local value = moduleBeingDefined.memoryMap:allocateInt {
		maxValue = 1
	}
	assert(value.shiftBy ~= nil)
	moduleBeingDefined.exportHooks[#moduleBeingDefined.exportHooks+1] = function(dev0)
		if  dev0:get_argument_value(arg_number) > 0.2 then
			value:setValue(1)
		else
		    value:setValue(0)
		end
	end
	document {
		identifier = msg,
		category = category,
		description = description,
		control_type = "EBK steg 1",
		inputs = {},
		outputs = {
			{ ["type"] = "integer",
			  suffix = "",
			  address = value.address,
			  mask = value.mask,
			  shift_by = value.shiftBy,
			  max_value = 1,
			  description = "0 if light is off, 0.2 if light is on"
			}
		}
	}
end

local function defineIndicatorLightEBK2(msg, arg_number, category, description)
	local value = moduleBeingDefined.memoryMap:allocateInt {
		maxValue = 1
	}
	assert(value.shiftBy ~= nil)
	moduleBeingDefined.exportHooks[#moduleBeingDefined.exportHooks+1] = function(dev0)
		if dev0:get_argument_value(arg_number) > 0.4 then
			value:setValue(1)
		else
		    value:setValue(0)
		end
	end
	document {
		identifier = msg,
		category = category,
		description = description,
		control_type = "EBK steg 2",
		inputs = {},
		outputs = {
			{ ["type"] = "integer",
			  suffix = "",
			  address = value.address,
			  mask = value.mask,
			  shift_by = value.shiftBy,
			  max_value = 1,
			  description = "0 if light is off, 0.5 if light is on"
			}
		}
	}
end

local function defineIndicatorLightEBK3(msg, arg_number, category, description)
	local value = moduleBeingDefined.memoryMap:allocateInt {
		maxValue = 1
	}
	assert(value.shiftBy ~= nil)
	moduleBeingDefined.exportHooks[#moduleBeingDefined.exportHooks+1] = function(dev0)
		if dev0:get_argument_value(arg_number) > 0.8 then
			value:setValue(1)
		else
		    value:setValue(0)
		end
	end
	document {
		identifier = msg,
		category = category,
		description = description,
		control_type = "EBK steg 3",
		inputs = {},
		outputs = {
			{ ["type"] = "integer",
			  suffix = "",
			  address = value.address,
			  mask = value.mask,
			  shift_by = value.shiftBy,
			  max_value = 1,
			  description = "0 if light is off, 0.7 if light is on"
			}
		}
	}
end

--[[--Vapenpanel--]]--
defineToggleSwitch("WEAPON_RELEASE_COVER", 2, 3302, 260, "Vapenpanel", "Weapon Emergency Release Cover")
definePushButton("WEAPON_RELEASE", 2, 3303, 261, "Vapenpanel", "Weapon Emergency Release Button")
defineToggleSwitch("TANK_RELEASE_COVER", 2, 3402, 262, "Vapenpanel", "External Tank Release Cover")
definePushButton("TANK_RELEASE", 2, 3320, 263, "Vapenpanel", "External Tank Release Button")
defineTumb("WEAPON_SELECT", 2, 3304, 264, 0.1, {0.0, 0.5}, nil, false, "Vapenpanel", "Weapon Selector Knob")
defineTumb("WEAPON_INTERVAL", 2, 3305, 265, 0.1, {0.0, 1.0}, nil, false, "Vapenpanel", "Weapon Interval Selector Mode Knob")
defineToggleSwitch("WEAPON_REL_MODE", 2, 3306, 266, "Vapenpanel", "Weapon Release Mode Switch")
defineToggleSwitch("RB_BK_REL_MODE",2, 3307, 267, "Vapenpanel", "RB-04/RB-15/BK Release Mode Switch")

--[[--Radarpanel--]]--
defineTumb("ANTI_JAM_MODE", 5, 3208, 217, 0.1, {0.0, 0.7}, nil, false, "Radarpanel", "Anti Jamming Mode (AS) Selector")
defineToggleSwitch("RADAR_GAIN", 5, 3209, 214, "Radarpanel", "Lin/Log Radar Gain Switch")
defineToggleSwitch("RADAR_PULSE_NORMAL_SHORT", 5, 3328, 218, "Radarpanel", "Pulse Normal/Short Switch")
defineToggleSwitch("RADAR_RECCE_ON_OFF", 5, 3350, 216, "Radarpanel", "Passive Recce On/Off Switch")
defineToggleSwitch("RADAR_MAINTENANCE_TEST", 5, 3914, 1006, "Radarpanel", "Radar/EL Maintenance Test")
defineToggleSwitch("DOPPLER_LAND_SEA_MODE", 21, 3001, 213, "Radarpanel", "Doppler Land/Sea Mode")
defineTumb("MASTER_MODE_SELECT", 22, 3107, 209, 0.16666667, {0, 1}, nil, false, "Radarpanel", "Master Mode Selector")
definePotentiometer("RADAR_BRIGHT", 5, 3923, 391, {0, 1},"Radarpanel" , "Radar Brightness")

--[[--Autopilot--]]--
definePushButton("SPAK", 22, 3301, 401,  "Autopilot",  "SPAK")
definePushButton("ATTITUDE_HOLD", 22, 3302, 402, "Autopilot", "Attitude Hold")
definePushButton("ALTITUDE_HOLD", 22, 3303, 403, "Autopilot", "Altitude Hold")

--[[--Instrumentpanel--]]--
defineToggleSwitch("REVERSAL", 7, 3001, 20, "Instrumentpanel", "Thrust Reverser On/Off")
defineToggleSwitch("SLAV_SI", 22, 3201, 323, "Instrumentpanel", "Slav SI")
defineToggleSwitch("HOJD_CISI", 22, 3200, 324, "Instrumentpanel", "HOJD CISI")
defineToggleSwitchToggleOnly("PARKING_BRAKE", 22, 3408, 22, "Instrumentpanel", "Parking Brake")
defineToggleSwitchToggleOnly("HUD_GLASS_POSITION", 22, 3401, 11, "Instrumentpanel", "HUD Reflector Glass Position")
--defineToggleSwitchToggleOnly("AFK_15_DEG_MODE", 22, 3402, 464, "Instrumentpanel", "AFK 15 Deg Mode")
defineToggleSwitchToggleOnly("AFK_MODE_3", 22, 3402, 464, "Instrumentpanel", "AFK Mode 3")
definePotentiometer("ALT_SET", 25, 3306, 2005, {0, 1},"Instrumentpanel" , "Altimeter Setting")
defineToggleSwitch("MASTER_CAUTION_RESET", 26, 3001, 446, "Instrumentpanel", "Master Caution Reset")
definePushButton("MAX_G_RESET", 25, 3722, 175, "Instrumentpanel", "Max G Reset")
definePotentiometer("HUD_BRIGHT", 25, 3409, 180, {0, 1},"Instrumentpanel" , "HUD Brightness Knob")
definePotentiometer("CLOCK_SET", 25, 3801, 135, {0, 1},"Instrumentpanel" , "Clock Setting")
defineFloat("ENGINE_RPM_100", 139, {-1, 1}, "Instrumentpanel", "Engine RPM 100")
defineFloat("ENGINE_RPM_10", 140, {0, 1}, "Instrumentpanel", "Engine RPM 10")
defineFloat("ENGINE_TEMP", 146, {0, 1}, "Instrumentpanel", "Engine Temp")
defineFloat("AIRSPEED_M/S", 100, {0, 1}, "Instrumentpanel", "Airspeed m/s")
defineFloat("MACH_METER_INTEGER", 101, {0, 1}, "Instrumentpanel", "Mach Meter Integer X.00")
defineFloat("MACH_METER_FIRST_DECIMAL", 102, {0, 1}, "Instrumentpanel", "Mach Meter First Decimal 0.X0")
defineFloat("MACH_METER_SECOND_DECIMAL", 103, {0, 1}, "Instrumentpanel", "Mach Meter Second Decimal 0.0X")
defineFloat("VERTICAL_ACCELERATION", 136, {-0.3, 0.8}, "Instrumentpanel", "Vertical Acceleration G Meter")
defineFloat("ALTIMETER_10000M", 114, {0, 1}, "Instrumentpanel", "Altimeter 10000 Meter")
defineFloat("ALTIMETER_1000M", 113, {0, 1}, "Instrumentpanel", "Altimeter 1000 Meter")
defineFloat("ALTIMETER_BARO_1_HPA", 115, {0, 1}, "Instrumentpanel", "Altimeter Baro 1 hPa 000X")
defineFloat("ALTIMETER_BARO_10_HPA", 116, {0, 1}, "Instrumentpanel", "Altimeter Baro 10 hPa 00X0")
defineFloat("ALTIMETER_BARO_100_HPA", 117, {0, 1}, "Instrumentpanel", "Altimeter Baro 100 hPa 0X00")
defineFloat("ALTIMETER_BARO_1000_HPA", 118, {0, 1}, "Instrumentpanel", "Altimeter Baro 1000 hPa X000")
defineFloat("ADI_PITCH", 105, {1, -1}, "Instrumentpanel", "ADI Pitch")
defineFloat("ADI_HEADING", 106, {1, -1}, "Instrumentpanel", "ADI Heading")
defineFloat("ADI_ROLL", 107, {-1, 1}, "Instrumentpanel", "ADI Roll")
defineFloat("ADI_VERTICAL_VELOCITY", 108, {-1, 1}, "Instrumentpanel", "ADI Vertical Velocity")
defineFloat("ADI_VERTICAL_ILS", 109, {1, -1}, "Instrumentpanel", "ADI Vertical ILS")
defineFloat("ADI_HORIZONTAL_ILS", 110, {1, -1}, "Instrumentpanel", "ADI Horizontal ILS")
defineFloat("ADI_SLIPBALL", 111, {-1, 1}, "Instrumentpanel", "ADI Slipball")
defineFloat("ADI_AOA_INDICATOR", 147, {0, 1}, "Instrumentpanel", "ADI AoA Indicator")
defineFloat("CI_HEADING", 128, {1, -1}, "Instrumentpanel", "CI Heading")
defineFloat("CI_COMMANDED_HEADING", 129, {1, 0}, "Instrumentpanel", "CI Commanded Heading")
defineFloat("MAGNETIC_HEADING", 127, {1, -1}, "Instrumentpanel", "Magnetic Heading")
defineFloat("DISTANCE_INDICATOR", 142, {0, 1}, "Instrumentpanel", "Distansindikator")
defineFloat("FUEL_LEVEL", 144, {0, 1}, "Instrumentpanel", "Fuel Level")
defineFloat("FUEL_NEEDED", 145, {0, 1}, "Instrumentpanel", "Fuel Needed")

--[[--Datapanel--]]--
definePushButton("DATAPANEL_KEY_0", 12, 3020, 290, "Datapanel", "Datapanel Key 0")
definePushButton("DATAPANEL_KEY_1", 12, 3021, 291, "Datapanel", "Datapanel Key 1")
definePushButton("DATAPANEL_KEY_2", 12, 3022, 292, "Datapanel", "Datapanel Key 2")
definePushButton("DATAPANEL_KEY_3", 12, 3023, 293, "Datapanel", "Datapanel Key 3")
definePushButton("DATAPANEL_KEY_4", 12, 3024, 294, "Datapanel", "Datapanel Key 4")
definePushButton("DATAPANEL_KEY_5", 12, 3025, 295, "Datapanel", "Datapanel Key 5")
definePushButton("DATAPANEL_KEY_6", 12, 3026, 296, "Datapanel", "Datapanel Key 6")
definePushButton("DATAPANEL_KEY_7", 12, 3027, 297, "Datapanel", "Datapanel Key 7")
definePushButton("DATAPANEL_KEY_8", 12, 3028, 298, "Datapanel", "Datapanel Key 8")
definePushButton("DATAPANEL_KEY_9", 12, 3029, 299, "Datapanel", "Datapanel Key 9")
defineTumb("DATAPANEL_SELECTOR", 23, 3009, 200, 0.1, {0.0, 0.6}, nil, false, "Datapanel", "Datapanel Selector")
defineToggleSwitch("DATA_IN_OUT", 23, 3008, 201, "Datapanel", "Data In/Out")
defineToggleSwitch("RENSA_BUTTON_COVER", 23, 3101, 300, "Datapanel", "Rensa Button Cover")
definePushButton("CK37_RENSA_CLEAR", 23, 3001, 301, "Datapanel", "CK37 Rensa Clear")

--[[--Navigeringspanel--]]--
definePushButton("NAV_SELECT_BTN_B1", 12, 3011, 271, "Navigeringspanel", "Navigation Selector Button B1")
definePushButton("NAV_SELECT_BTN_B2", 12, 3012, 272, "Navigeringspanel", "Navigation Selector Button B2")
definePushButton("NAV_SELECT_BTN_B3", 12, 3013, 273, "Navigeringspanel", "Navigation Selector Button B3")
definePushButton("NAV_SELECT_BTN_B4", 12, 3014, 274, "Navigeringspanel", "Navigation Selector Button B4")
definePushButton("NAV_SELECT_BTN_B5", 12, 3015, 275, "Navigeringspanel", "Navigation Selector Button B5")
definePushButton("NAV_SELECT_BTN_B6", 12, 3016, 276, "Navigeringspanel", "Navigation Selector Button B6")
definePushButton("NAV_SELECT_BTN_B7", 12, 3017, 277, "Navigeringspanel", "Navigation Selector Button B7")
definePushButton("NAV_SELECT_BTN_B8", 12, 3018, 278, "Navigeringspanel", "Navigation Selector Button B8")
definePushButton("NAV_SELECT_BTN_B9", 12, 3019, 279, "Navigeringspanel", "Navigation Selector Button B9")
definePushButton("NAV_SELECT_BTN_BX", 12, 3010, 280, "Navigeringspanel", "Navigation Selector Button BX")
definePushButton("NAV_SELECT_BTN_LS", 12, 3009, 270, "Navigeringspanel", "Navigation Selector Button LS")
definePushButton("NAV_SELECT_BTN_L_MAL", 12, 3008, 281, "Navigeringspanel", "Navigation Selector Button L MAL")
defineTumb("TILS_CHANNEL_SELECT", 22, 3512, 282, 0.1, {0.0, 1.0}, nil, false, "Navigeringspanel", "TILS Channel Selection")
defineToggleSwitch("RADAR_ALTIMETER_POWER", 20, 3002, 283, "Navigeringspanel", "Radar Altimeter Power")
defineToggleSwitch("DME_SELECTOR", 18, 3919, 1206, "Navigeringspanel", "DME Selector")

--[[Belysning--]]--
defineToggleSwitch("ANTI_COLLISION_LIGHTS", 17, 3001, 250, "Manöverpanel Ytterbelysning", "Anti Collision Lights")
defineTumb("NAVIGATION_LIGHTS", 17, 3002, 251, 1, {-1,1}, nil, false, "Manöverpanel Ytterbelysning", "Navigation Lights")
defineToggleSwitch("FORMATION_LIGHTS", 17, 3003, 252, "Manöverpanel Ytterbelysning", "Formation Lights")
defineToggleSwitch("POSITION_LIGHTS", 17, 3004, 253, "Manöverpanel Ytterbelysning", "Position Lights")
defineToggleSwitch("TAXI_LANDING_LIGHTS", 17, 3009, 3554, "Manöverpanel Ytterbelysning", "Taxi/Landing Lights")
definePotentiometer("FLOOD_LIGHTS", 17, 3007, 393, {0, 1}, "Belysningspanel", "Flood Lights")
definePotentiometer("PANEL_LIGHTS", 17, 3006, 392, {0, 1}, "Belysningspanel", "Panel Lights")
defineTumb("POSITION_LIGHTS_BRIGHTNESS", 17, 3005, 254, 0.1, {0.0, 0.2}, nil, false, "Formljus/ledljus", "Position Lights Brightness")
definePotentiometer("INSTRUMENT_LIGHTS", 17, 3008, 394, {0, 1}, "Belysningspanel", "Instrument Lights")

--[[--Startpanel--]]--
defineToggleSwitch("START_SYSTEM", 18, 3001, 206, "Startpanel", "Start System")
defineToggleSwitch("LOW_PRES_FUEL_VALVE", 18, 3002, 204, "Startpanel", "Low Pressure Fuel Valve")
defineIndicatorLight("LT_KRAN_LAMP", 404, "Startpanel", "LT kran Lampa")
defineIndicatorLight("START_Sol", 206, "Startpanel", "Start solenoid")
defineToggleSwitch("IGNITION_SYSTEM", 18, 3003, 205, "Startpanel", "Ignition System")
definePushButton("RESTART", 18, 3004, 208, "Startpanel", "Restart")
defineToggleSwitch("GENERATOR", 19, 3002, 207, "Startpanel", "Generator")
defineToggleSwitch("MAIN_ELECTRIC_POWER", 19, 3001, 203, "Startpanel", "Main Electric Power")
definePotentiometer("AUTO_YAW_TRIM", 25, 3732, 211, {-1, 1},"Startpanel" , "Autopilot Yaw Trim")
defineToggleSwitch("YAW_TRIM_COVER", 22, 3741, 493, "Startpanel", "Autopilot Yaw Trim Cover")

--[[--Motorpanel--]]--
defineToggleSwitch("HIGH_PRES_FUEL_VALVE", 18, 3005, 202, "Motorpanel", "High Pressure Fuel Valve")
defineToggleSwitch("ENGINE_DEICE", 18, 3008, 310, "Motorpanel", "Engine De-Ice")
defineToggleSwitch("MANUAL_FUEL_REG", 18, 3007, 316, "Motorpanel", "Manual Fuel Regulator")
defineToggleSwitch("BACKUP_GENERATOR", 19, 3003, 312, "Motorpanel", "Backup Generator")
defineToggleSwitch("MAN_AFTERBURN_FUEL_REG", 18, 3006, 313, "Motorpanel", "Manual Afterburner Fuel Regulator")
defineToggleSwitch("PITCH_GEAR_MODE", 22, 3210, 311, "Motorpanel", "Pitch Gear Automatic/Landing")

--[[--Säkringpanel--]]--
defineToggleSwitch("CB_AUTOPILOT", 18, 3905, 302, "Säkringspanel", "CB Autopilot SA")
defineToggleSwitch("CB_HIGH_ALPHA_WARN", 18, 3906, 303, "Säkringspanel", "CB High Alpha Warning")
defineToggleSwitch("CB_TRIM_SYSTEM", 18, 3907, 304, "Säkringspanel", "CB Trim System")
defineToggleSwitch("CB_CI_SI", 18, 3908, 305, "Säkringspanel", "CB CI/SI")
defineToggleSwitch("CB_EJECTION_SYSTEM", 18, 3909, 306, "Säkringspanel", "CB Ejection System")
defineToggleSwitch("CB_ENGINE", 18, 3910, 307, "Säkringspanel", "CB Engine")

--[[--VänsterPanel--]]--
defineToggleSwitch("GEAR_HANDLE", 22, 3719, 12, "VänsterPanel", "Gear Handle")
defineTumb("AFK_LEVER", 18, 3304, 13, 1.138, {0, 1.138}, nil, false, "VänsterPanel", "AFK Lever")
defineToggleSwitch("DATA_CARTRIDGE", 18, 3925, 4200, "VänsterPanel", "Insert/Remove Data Cartridge")
defineTumb("CANOPY_OPEN_CLOSE", 22, 3406, 9, 1, {-1, 1}, nil, false, "VänsterPanel", "Canopy Open/Close")
definePotentiometer("MASTER_VOL", 27, 3006, 399, {0, 1},"VänsterPanel" , "Master Volume / Sidewinder Tone")
definePushButton("MISSILE_SELECT_BUTTON", 18, 3000, 400, "VänsterPanel", "Missile Select Button")
definePushButton("COUNTERMEASURE_FAST_RELEASE", 22, 3001, 184, "VänsterPanel", "Countermeasure Fast Release")
definePushButton("CANOPY_JETTISON", 22, 3407, 210, "VänsterPanel", "Canopy Jettison")
definePushButton("ROLL_CENTER", 25, 3305, 212, "VänsterPanel", "Roll Centering")
definePushButton("WARNING_PANEL_TEST", 26, 3002, 344, "VänsterPanel", "Warning Panel Light Test")
defineToggleSwitch("CABIN_AIR_VALVE", 21, 3000, 398, "VänsterPanel", "Cabin Air Valve")

--[[--Trimpanel--]]--
defineToggleSwitch("EMERGENCY_ROLL_TRIM", 22, 3716, 390, "Trimpanel", "Emergency Roll Trim")
defineToggleSwitch("EMERGENCY_PITCH_TRIM", 22, 3717, 389, "Trimpanel", "Emergency Pitch Trim")
defineToggleSwitch("EMERGENCY_YAW_TRIM", 22, 3918, 388, "Trimpanel", "Emergency Yaw Trim")

--[[--HögerPanel--]]--
defineToggleSwitch("OXYGEN_LEVER", 22, 3718, 176, "HögerPanel", "Oxygen Lever")
defineTumb("FLIGHT_RECORDER", 18, 3924, 384, 0.5, {0.0, 1.0}, nil, false, "HögerPanel", "Flight Recorder")
defineToggleSwitch("TILS_CHANNEL_LAYER", 22, 3511, 285, "HögerPanel", "TILS Channel Layer Selection")
defineToggleSwitch("EJECTION_SEAT_ARM", 22, 3405, 21, "HögerPanel", "Ejection Seat Arm")
definePushButton("INDICATOR_SYSTEM_TEST", 26, 3004, 315, "HögerPanel", "Indicator System Test")
definePotentiometer("DRYSUIT", 21, 3917, 396, {0, 1},"HögerPanel" , "Drysuit Ventilation Adjustment")
defineToggleSwitch("IGNITION_COILS", 5, 3918, 395, "HögerPanel", "Ignition Coils")

--[[--Manöverpanel KA--]]--
defineTumb("JAMMER_MODE_SELECTOR", 28, 3024, 317, 0.1, {0.0, 0.4}, nil, false, "Manöverpanel KA", "Jammer Mode Selector")
defineTumb("JAMMER_BAND_SELECTOR", 28, 3025, 318, 0.1, {0.0, 0.4}, nil, false, "Manöverpanel KA", "Jammer Band Selector") 

--[[--Manöverpanel KB--]]--
defineTumb("COUNTERMEASURE_MODE_SELECTOR", 28, 3026, 319, 0.1, {0.0, 0.4}, nil, false, "Manöverpanel KB", "Countermeasure Operation Mode Selector")
defineTumb("COUNTERMEASURE_STREAK_MODE_SELECTOR", 28, 3027, 320, 0.1, {0.0, 0.1}, nil, false, "Manöverpanel KB", "Countermeasure Streak Mode Selector")
defineTumb("COUNTERMEASURE_CHAFF_FLARES_SELECTOR", 28, 3028, 322, 0.1, {0.0, 0.2}, nil, false, "Manöverpanel KB", "Countermeasure Chaff/Flares Selector")
defineTumb("COUNTERMEASURE_RELEASE_MODE", 22, 3001, 184, 1, {-1, 1}, nil, false, "Manöverpanel KB", "Countermeasure Release Mode") --3030
defineTumb("RADAR_WARN_SELECT", 24, 3004, 321, 0.1, {0.0, 0.2}, nil, false, "Manöverpanel KB", "Radar Warning Indication Selector")

--[[--Reservinstrument-]]--
defineFloat("BACKUP_INDICATED_AIRSPEED", 138, {0, 1}, "Reservinstrument", "Backup Indicated Airspeed")
defineFloat("BACKUP_ALTIMETER_10000M", 125, {0, 1}, "Reservinstrument", "Backup Altimeter 10000 Meter")
defineFloat("BACKUP_ALTIMETER_1000M", 124, {0, 1}, "Reservinstrument", "Backup Altimeter 1000 Meter")
defineFloat("BACKUP_PITCH", 121, {1, -1}, "Reservinstrument", "Backup Pitch")
defineFloat("BACKUP_ROLL", 122, {1, -1}, "Reservinstrument", "Backup Roll")
definePotentiometer("BACKUP_ALT_SETTING", 22, 3721, 126, {0, 1}, "Reservinstrument", "Backup Altimeter Setting")
definePushButton("BACK_ADI_CAGE", 25, 3720, 123, "Reservinstrument", "Backup ADI Cage")

defineIndicatorLight("SPAK_LAMP", 401, "Indikeringslampor", "SPAK Lamp")
defineIndicatorLight("ATT_LAMP", 402, "Indikeringslampor", "ATT Lamp")
defineIndicatorLight("HOJD_LAMP", 403, "Indikeringslampor", "HOJD Lamp")

--[[--CentralIndikator--]]--
------------------------------------------------------------------------------
---- Added by outbaxx
------------------------------------------------------------------------------
defineIndicatorLight("RWR_LAMP_3", 451, "CentralIndikator", "Radarvarning kl 1")
defineIndicatorLight("RWR_LAMP_9", 452, "CentralIndikator", "Radarvarning kl 3")
defineIndicatorLight("RWR_LAMP_15", 453, "CentralIndikator", "Radarvarning kl 5")
defineIndicatorLight("RWR_LAMP_21", 454, "CentralIndikator", "Radarvarning kl 7")
defineIndicatorLight("RWR_LAMP_27", 455, "CentralIndikator", "Radarvarning kl 9")
defineIndicatorLight("RWR_LAMP_33", 456, "CentralIndikator", "Radarvarning kl 11")

--[[--Indikeringstablå--]]--
-------------------------------------------------------------------------------
-- Edited by Outbaxx for 16-bit boundry
--Vänster Indikeringstablå
-------------------------------------------------------------------------------
defineIndicatorLight("VT_VA1", 406, "Indikeringstablå", "BRAND 1")
defineIndicatorLight("VT_VA2", 407, "Indikeringstablå", "BRAND 2")
defineIndicatorLight("VT_VA3", 408, "Indikeringstablå", "BRA UPPF")
defineIndicatorLight("VT_VA4", 409, "Indikeringstablå", "X-TANK BRA")
defineIndicatorLight("VT_VB1", 410, "Indikeringstablå", "TANKPUMP")
defineIndicatorLight("VT_VB2", 411, "Indikeringstablå", "LANDSTALL")
defineIndicatorLight("VT_VB3", 412, "Indikeringstablå", "FORV FORBJ")
defineIndicatorLight("VT_VB4", 413, "Indikeringstablå", "NOSSTALL")
defineIndicatorLight("VT_VC1", 414, "Indikeringstablå", "V STALL")
defineIndicatorLight("VT_VC2", 415, "Indikeringstablå", "H STALL")
defineIndicatorLight("VT_VC3", 416, "Indikeringstablå", "TIPPVAXEL")
defineIndicatorLight("VT_VC4", 417, "Indikeringstablå", "ELFEL")
defineIndicatorLight("VT_VD1", 418, "Indikeringstablå", "RESERV EFF")
defineIndicatorLight("VT_VD2", 419, "Indikeringstablå", "HYDR-TR 2")
defineIndicatorLight("VT_VD3", 420, "Indikeringstablå", "HYDR-TR 1")
defineIndicatorLight("VT_VD4", 421, "Indikeringstablå", "AFK-FEL")
defineIndicatorLight("VT_VE1", 422, "Indikeringstablå", "EJ REV")
defineIndicatorLight("VT_VE2", 344, "Indikeringstablå", "GRON LINJE")
defineIndicatorLight("VT_VE3", 423, "Indikeringstablå", "OLJETRYCK")
--Samma som kontrlamptbalå tills argument finns
defineIndicatorLight("VT_VE4", 344, "Indikeringstablå", "OLJETEMP")
-------------------------------------------------------------------------
 ---- Added by outbaxx for 16-bit Boundry
-------------------------------------------------------------------------
defineIndicatorLightEBK1("EBK_STEG1_LAMPA", 405, "Indikeringslampor", "EBK1_lampa")
defineIndicatorLightEBK2("EBK_STEG2_LAMPA", 405, "Indikeringslampor", "EBK2_lampa")
defineIndicatorLightEBK3("EBK_STEG3_LAMPA", 405, "Indikeringslampor", "EBK3_lampa")
defineIndicatorLight("H_VARN_VA_LAMPA", 444, "Indikeringslampor", "Huvudvarning vanster")
defineIndicatorLight("H_VARN_HO_LAMPA", 445, "Indikeringslampor", "Huvudvarning hoger")
defineIndicatorLight("HOJD_VARNING", 450, "Indikeringslampor", "Hojdvarning")
defineIndicatorLight("REVERSERING_LAMPA", 460, "Indikeringslampor", "Reversering vald")
defineIndicatorLight("FALLD_LAST_LAMPA", 461, "Indikeringslampor", "Falld last")
defineIndicatorLight("TRANS_REV_AVDR", 462, "Indikeringslampor", "TransRevAvdr")
defineIndicatorLight("AFK_LAMPA", 463, "Indikeringslampor", "AFK inkopplad")
defineIndicatorLight("AFK_15_LAMPA", 464, "Indikeringslampor", "AFK 15 vald")
defineIndicatorLight("IFF_LAMPA", 666, "Indikeringslampor", "IFF Lampa")
------------------------------------------------------------------------
--Höger Indikeringstablå
------------------------------------------------------------------------
defineIndicatorLight("VT_VF1", 424, "Indikeringstablå", "SPAK")
defineIndicatorLight("VT_VF2", 425, "Indikeringstablå", "HALL-FUNK")
defineIndicatorLight("VT_VF3", 426, "Indikeringstablå", "RHM FEL")
defineIndicatorLight("VT_VF4", 427, "Indikeringstablå", "ROLLVAXEL")
defineIndicatorLight("VT_VG1", 428, "Indikeringstablå", "CK")
defineIndicatorLight("VT_VG2", 429, "Indikeringstablå", "KABINHOJD")
defineIndicatorLight("VT_VG3", 430, "Indikeringstablå", "HUV o STOL")
defineIndicatorLight("VT_VG4", 431, "Indikeringstablå", "TANDSYST")
defineIndicatorLight("VT_VH1", 432, "Indikeringstablå", "STARTSYST")
defineIndicatorLight("VT_VH2", 433, "Indikeringstablå", "MAN BR REG")
defineIndicatorLight("VT_VH3", 434, "Indikeringstablå", "SYRGAS")
defineIndicatorLight("VT_VH4", 435, "Indikeringstablå", "BRA < 24")
defineIndicatorLight("VT_VI1", 436, "Indikeringstablå", "BRAND GTS")
defineIndicatorLight("VT_VI2", 437, "Indikeringstablå", "TILS")
defineIndicatorLight("VT_VI3", 438, "Indikeringstablå", "NAV-SYST")
defineIndicatorLight("VT_VI4", 439, "Indikeringstablå", "KB-V SLUT")
defineIndicatorLight("VT_VJ1", 440, "Indikeringstablå", "KB-H/KA SL")
defineIndicatorLight("VT_VJ2", 441, "Indikeringstablå", "FACKL SL")
defineIndicatorLight("VT_VJ3", 442, "Indikeringstablå", "MOTVERK")
defineIndicatorLight("VT_VJ4", 443, "Indikeringstablå", "LUFTBROMS")

--[[--Warning Panel--]]--


--[[--Actual Gauge Values--]]--

local function getRPM()
     local returnValue = ((GetDevice(0):get_argument_value(139))*55+55)
     return returnValue
end
defineIntegerFromGetter("Motorvarv", getRPM, 65000, "Instrumentpanel", "Motorvarv")

local function getEngineTemp()
     local returnValue = ((GetDevice(0):get_argument_value(146))*700+100)
     return returnValue
end
defineIntegerFromGetter("ENGINE_TEMP_VALUE", getEngineTemp, 65000, "Instrumentpanel", "Engine Temp Value")

local function getAirspeed()
     local returnValue = ((-707.23*(GetDevice(0):get_argument_value(100))^4)+(1843.8*(GetDevice(0):get_argument_value(100))^3)-(647.84*(GetDevice(0):get_argument_value(100))^2)+(810.63*(GetDevice(0):get_argument_value(100)))+100.03)
     return returnValue
end
defineIntegerFromGetter("AIRSPEED_VALUE", getAirspeed, 65000, "Instrumentpanel", "Airspeed Value")

local function getAlt()
     local returnValue = ((GetDevice(0):get_argument_value(114))*10000)
     return returnValue
end
defineIntegerFromGetter("ALTITUDE_VALUE", getAlt, 65000, "Instrumentpanel", "Altitude Value")

local function getFuelLev()
     local returnValue = ((GetDevice(0):get_argument_value(144))*135)
     return returnValue
end
defineIntegerFromGetter("FUEL_LEVEL_VALUE", getFuelLev, 65000, "Instrumentpanel", "Fuel Level Value")

local function getFuelNeed()
     local returnValue = ((GetDevice(0):get_argument_value(145))*135)
     return returnValue
end
defineIntegerFromGetter("FUEL_NEEDED_VALUE", getFuelNeed, 65000, "Instrumentpanel", "Fuel Needed Value")

local function getCIHDG()
	 local heading = 0
	 if (GetDevice(0):get_argument_value(128)) <= 0 then
	 heading = ((180 * (GetDevice(0):get_argument_value(128))) + 360)
	 else
     heading = (180 * (GetDevice(0):get_argument_value(128)))
	 end
     return heading
end
defineIntegerFromGetter("CI_HEADING_VALUE", getCIHDG, 65000, "Instrumentpanel", "CI Heading Value")

local function getCICMDHDG()
     local returnValue = ((GetDevice(0):get_argument_value(129)) * 360)
     return returnValue
end
defineIntegerFromGetter("CI_COMMAND_HEADING_VALUE", getCICMDHDG, 65000, "Instrumentpanel", "CI Commanded Heading Value")

--[[--Manöverpanel FR22--]]--
defineRotary("FR22_INNER_LEFT_KNOB", 31, 3003, 171, "Manöverpanel FR22", "Radio Frequency Knob Inner Left")
defineRotary("FR22_OUTER_LEFT_KNOB", 31, 3004, 172, "Manöverpanel FR22", "Radio Frequency Knob Outer Left")
defineRotary("FR22_INNER_RIGHT_KNOB", 31, 3005, 173, "Manöverpanel FR22", "Radio Frequency Knob Inner Right")
defineRotary("FR22_OUTER_RIGHT_KNOB", 31, 3006, 174, "Manöverpanel FR22", "Radio Frequency Knob Outer Right")
defineToggleSwitchToggleOnly("FR22_SET_MODULATION", 31, 3008, 170, "Manöverpanel FR22", "Radio Manual Frequency Setting Modulation")
 ---- added by Warlord
definePushButton("FR22_FLIGHT_0", 34, 3210,372, "Manöverpanel FR22", "Flight 0")
definePushButton("FR22_FLIGHT_1", 34, 3211,373, "Manöverpanel FR22", "Flight 1")
definePushButton("FR22_FLIGHT_2", 34, 3212,374, "Manöverpanel FR22", "Flight 2")
definePushButton("FR22_FLIGHT_3", 34, 3213,375, "Manöverpanel FR22", "Flight 3")
definePushButton("FR22_FLIGHT_4", 34, 3214,376, "Manöverpanel FR22", "Flight 4")
definePushButton("FR22_FLIGHT_5", 34, 3215,377, "Manöverpanel FR22", "Flight 5")
definePushButton("FR22_FLIGHT_6", 34, 3216,378, "Manöverpanel FR22", "Flight 6")
definePushButton("FR22_FLIGHT_7", 34, 3217,379, "Manöverpanel FR22", "Flight 7")
definePushButton("FR22_FLIGHT_8", 34, 3218,380, "Manöverpanel FR22", "Flight 8")
definePushButton("FR22_FLIGHT_9", 34, 3219,381, "Manöverpanel FR22", "Flight 9")
definePushButton("FR22_CHANNEL_H", 34, 3200,362, "Manöverpanel FR22", "Channel H")
definePushButton("FR22_SPECIAL_1", 34, 3201,363, "Manöverpanel FR22", "Special 1")
definePushButton("FR22_SPECIAL_2", 34, 3202,364, "Manöverpanel FR22", "Special 2")
definePushButton("FR22_SPECIAL_3", 34, 3203,365, "Manöverpanel FR22", "Special 3")
definePushButton("FR22_MINUS", 34, 3204,366, "Manöverpanel FR22", "Minus")
definePushButton("FR22_CHANNEL_AG", 34, 3205,367, "Manöverpanel FR22", "Channel A/G")
definePushButton("FR22_CHANNEL_B", 34, 3206,368, "Manöverpanel FR22", "Channel B")
definePushButton("FR22_CHANNEL_CF", 34, 3207,369, "Manöverpanel FR22", "Channel C/F")
definePushButton("FR22_CHANNEL_C2", 34, 3208,370, "Manöverpanel FR22", "Channel C2")
definePushButton("FR22_CHANNEL_DE", 34, 3209,371, "Manöverpanel FR22", "Channel D/E")
definePushButton("FR22_GROUND_COM", 34, 3011,382, "Manöverpanel FR22", "Ground Intercom")
defineTumb("FR22_MODE", 34, 3110, 386, 0.1, {0.0, 0.5}, nil, false, "Manöverpanel FR22", "FR22 Mode Selector")
defineTumb("FR22_BASE", 34, 3230, 2002, 0.1, {0.0, 1.0}, nil, false, "Manöverpanel FR22", "FR22 Base Selector")
defineTumb("FR22_GROUP", 34, 3307, 360, 0.1, {0.0, 1.0}, nil, false, "Manöverpanel FR22", "FR22 Group Selector")
defineRotary("FR22_VOL", 21, 3112, 385, "Manöverpanel FR22" , "Radio Volume")

--[[--Manöverpanel SSR--]]--
definePushButton("RADAR_IFF_ID", 5, 3922, 1205, "Manöverpanel SSR", "IFF Identification")
defineToggleSwitch("IFF_TRANSPONDER_POWER", 18, 3920, 1203, "Manöverpanel SSR", "IFF/Transponder Power")
defineToggleSwitch("IFF_CHANNEL", 18, 3921, 1204, "Manöverpanel SSR", "IFF Channel Selector")

--[[--IFF Panel-]]--
defineToggleSwitch("IFF_POWER", 21, 3000, 308, "IFF Panel", "IFF Power")
defineTumb("IFF_CODE", 21, 3000, 309, 0.1, {0.0, 1.0}, nil, false, "IFF Panel", "IFF Code")

--[[--Manöverpanel FK-]]--
definePotentiometer("MAG_CORRECTION", 25, 3724, 1201, {0, 1},"Manöverpanel FK" , "Magnetic Declination Correction")
defineToggleSwitch("MAG_DEC_COVER", 22, 3742, 1200, "Manöverpanel FK", "Magnetic Declination Cover")
definePotentiometer("TEST_MODE", 21, 3913, 675, {0, 1},"Manöverpanel FK" , "Maintenance Testing Mode")
definePotentiometer("DE-ICE", 21, 3912, 286, {0, 1},"Manöverpanel FK" , "Windscreen De-Ice")


--[[--Styrenheter--]]--
defineFloat("STICK_PITCH", 2, {-1, 1}, "Raw Gauge Values", "Stick Pitch")
defineFloat("STICK_ROLL", 3, {-1, 1}, "Raw Gauge Values", "Stick Roll")
defineFloat("PEDALS", 4, {-1, 1}, "Raw Gauge Values", "Pedals")
defineFloat("THROTTLE", 5, {0, 1}, "Raw Gauge Values", "Throttle")

--
--
defineToggleSwitch("EMERGENCY_LIGHTS", 17, 3010, 3555, "Belysningspanel", "Emergency Lights")
defineToggleSwitch("TRIGGER_SAFETY_BRACKET", 2, 3300, 8, "Styrspak", "Trigger Safety Bracket")
--function default_axis(hint_,device_,command_,arg_, default_, gain_,updatable_,relative_)
--function default_axis_limited(hint_,device_,command_,arg_, default_, gain_,updatable_,relative_, arg_lim_)
--found no argument
-- elements["SnabbresM-PTR"] = default_button(_("Snabbresning"), devices.FLIGHTDATAUNIT, 3091, 0) left bottom radar display
-- elements["PNT_CLOCK_RIGHT"] = default_button(_("Stopwatch Start/Stop/Reset"),devices.FLIGHTDATAUNIT, 3802, 0) right upper clock

------------------------------------------------------------------------------------
---- Added by Outbaxx
------------------------------------------------------------------------------------
---------------------------------------------------------------------------------------
-- Code for 1st DATADISPLAY	3 digits
---------------------------------------------------------------------------------------
local function getDataDisplay1To3()
    local data_1 = ""
    if GetDevice(0):get_argument_value(951) < -1.0 then
       data_1 = " "
    else
	if GetDevice(0):get_argument_value(951) > -0.4 and GetDevice(0):get_argument_value(951) < -0.1  then
        data_1 = "-"
		else
     data_1 = string.format("%.1f", GetDevice(0):get_argument_value(951)):sub(3)
    end
	end
	local data_2 = ""
    if GetDevice(0):get_argument_value(952) < -1.0  then
        data_2 = " "
    else
	if GetDevice(0):get_argument_value(952) > -0.4 and GetDevice(0):get_argument_value(952) < -0.1  then
        data_2 = "-"
		else
     data_2 = string.format("%.1f", GetDevice(0):get_argument_value(952)):sub(3)
	end
	end
	local data_3 = ""
    if GetDevice(0):get_argument_value(953) <  -1.0  then
        data_3 = " "
	else
	if GetDevice(0):get_argument_value(953) > -0.4 and GetDevice(0):get_argument_value(953) < -0.1  then
        data_3 = "-"
		else
	 data_3 = string.format("%.1f", GetDevice(0):get_argument_value(953)):sub(3)
	end
	end
	return data_1 .. data_2 .. data_3
	end
	defineString("DATADISPLAY1to3", getDataDisplay1To3, 3, "Datapanel", "DATADISPLAY1")
---------------------------------------------------------------------------------------
-- Code for 2nd DATADISPLAY	3 digits
---------------------------------------------------------------------------------------
local function getDataDisplay4To6()	
	local data_4 = ""

    if GetDevice(0):get_argument_value(954) < -1.0 then
        data_4 = " "
		else
	if GetDevice(0):get_argument_value(954) > -0.4 and GetDevice(0):get_argument_value(954) < -0.1  then
        data_4 = "-"
		else
	 data_4 = string.format("%.1f", GetDevice(0):get_argument_value(954)):sub(3)
	end
	end

	local data_5 = ""
    if GetDevice(0):get_argument_value(955) < -1.0 then
        data_5 = " "
    else
	if GetDevice(0):get_argument_value(955) > -0.4 and GetDevice(0):get_argument_value(955) < -0.1  then
        data_5 = "-"
		else
	 data_5 = string.format("%.1f", GetDevice(0):get_argument_value(955)):sub(3)
	end
	end
	
	local data_6 = ""
    if GetDevice(0):get_argument_value(956) < -1.0 then
        data_6 = " "
    else
	if GetDevice(0):get_argument_value(956) > -0.4 and GetDevice(0):get_argument_value(956) < -0.1  then
        data_6 = "-"
		else
	 data_6 = string.format("%.1f", GetDevice(0):get_argument_value(956)):sub(3)
	end
	end
	
	return data_4 .. data_5 .. data_6
end
	defineString("DATADISPLAY4to6", getDataDisplay4To6, 3, "Datapanel", "DATADISPLAY2")

--[[--Destinationsindikator--]]--	
-------------------------------------------------------------------
--Code for destinaton indicator display
-------------------------------------------------------------------
local function getAJS37DestIndicatorV()
	local li = list_indication(1)
	local m = li:gmatch("-----------------------------------------\n([^\n]+)\n([^\n]*)\n")
	while true do
		local name, value = m()
        if not name then break end
		if name == "Dest1"	
			then
			if value == "L" then return "0" else
			if value == "O" then return "1" else
			if value == "F" then return "2" else
			if value == "B" then return "3" else
			if value == "M" then return "4" else
			if value == "X" then return "5" else
			if value == "S" then return "6" else
			if value == "U" then return "7" else
			if value == "E" then return "8" else
			if value == "R" then return "9" else
			return value:sub(1)
											end
										end
									end
								end
							end
						end
					end
				end
			end			
		end
    end
end
	
return ""
end
 
defineString("AJS37_DEST_IND_DISPLAY_V", getAJS37DestIndicatorV, 1, "Destinationsindikator", "DestinationsindikatorV")

local function getAJS37DestIndicatorH()
	local li = list_indication(1)
	local m = li:gmatch("-----------------------------------------\n([^\n]+)\n([^\n]*)\n")
	while true do
		local name, value = m()
        if not name then break end
		if name == "Dest2"
			then
			if value == "S" then return "0" else
			return value:sub(1)
			end
		end
    end
return ""
end

 defineString("AJS37_DEST_IND_DISPLAY_H", getAJS37DestIndicatorH, 1, "Destinationsindikator", "DestinationsindikatorH")


BIOS.protocol.endModule()
