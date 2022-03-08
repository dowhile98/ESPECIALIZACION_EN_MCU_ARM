function CodeDefine() { 
this.def = new Array();
this.def["SimpleGPIO_M_"] = {file: "SimpleGPIO_c.html",line:38,type:"var"};
this.def["SimpleGPIO_M"] = {file: "SimpleGPIO_c.html",line:39,type:"var"};
this.def["SimpleGPIO_step"] = {file: "SimpleGPIO_c.html",line:42,type:"fcn"};
this.def["SimpleGPIO_initialize"] = {file: "SimpleGPIO_c.html",line:57,type:"fcn"};
this.def["RT_MODEL_SimpleGPIO"] = {file: "SimpleGPIO_types_h.html",line:40,type:"type"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:65,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:66,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:67,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:68,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:69,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:79,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:80,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:81,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:82,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:83,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:84,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:85,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:86,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:104,type:"type"};
this.def["main.c:OverrunFlags"] = {file: "main_c.html",line:41,type:"var"};
this.def["main.c:autoReloadTimerLoopVal_S"] = {file: "main_c.html",line:44,type:"var"};
this.def["remainAutoReloadTimerLoopVal_S"] = {file: "main_c.html",line:47,type:"var"};
this.def["main"] = {file: "main_c.html",line:55,type:"fcn"};
this.def["SysTick_Handler"] = {file: "stm32xxxx_it_c.html",line:37,type:"fcn"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["SimpleGPIO_c.html"] = "../SimpleGPIO.c";
	this.html2Root["SimpleGPIO_c.html"] = "SimpleGPIO_c.html";
	this.html2SrcPath["SimpleGPIO_h.html"] = "../SimpleGPIO.h";
	this.html2Root["SimpleGPIO_h.html"] = "SimpleGPIO_h.html";
	this.html2SrcPath["SimpleGPIO_private_h.html"] = "../SimpleGPIO_private.h";
	this.html2Root["SimpleGPIO_private_h.html"] = "SimpleGPIO_private_h.html";
	this.html2SrcPath["SimpleGPIO_types_h.html"] = "../SimpleGPIO_types.h";
	this.html2Root["SimpleGPIO_types_h.html"] = "SimpleGPIO_types_h.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["STM32_Config_h.html"] = "../STM32_Config.h";
	this.html2Root["STM32_Config_h.html"] = "STM32_Config_h.html";
	this.html2SrcPath["SimpleGPIO_External_Functions_h.html"] = "../SimpleGPIO_External_Functions.h";
	this.html2Root["SimpleGPIO_External_Functions_h.html"] = "SimpleGPIO_External_Functions_h.html";
	this.html2SrcPath["main_c.html"] = "../main.c";
	this.html2Root["main_c.html"] = "main_c.html";
	this.html2SrcPath["stm32xxxx_it_c.html"] = "../stm32xxxx_it.c";
	this.html2Root["stm32xxxx_it_c.html"] = "stm32xxxx_it_c.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"SimpleGPIO_c.html","SimpleGPIO_h.html","SimpleGPIO_private_h.html","SimpleGPIO_types_h.html","rtwtypes_h.html","STM32_Config_h.html","SimpleGPIO_External_Functions_h.html","main_c.html","stm32xxxx_it_c.html"];
