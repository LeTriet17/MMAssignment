function [png]=MHHTH_B3_pdf()
png.PN_name = 'MHHTH_B3'
png.set_of_Ps={'Wait','Inside','Done','Free','Busy','Docu'}
png.set_of_Ts={'Start','Change','End'}
png.set_of_As={'Wait','Start',1,'Start','Inside',1,'Inside','Change',1,'Change','Done',1,'Free','Start',1,'Start','Busy',1,'Busy','Change',1,'Change','Docu',1,'Docu','End',1,'End','Free',1}