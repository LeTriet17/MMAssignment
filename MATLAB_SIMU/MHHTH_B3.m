clear all; clc; 
global global_info
global_info.MAX_LOOP = 15;

pns = pnstruct('MHHTH_B3_pdf');

dyn.m0 = {'Wait',3, 'Done',1, 'Free',1};
pni = initialdynamics(pns, dyn); 

Sim_Results = gpensim(pni); % perform simulation runs
prnss(Sim_Results);  % print the simulation results 
plotp(Sim_Results, {'Wait','Inside','Done','Free','Busy','Docu'}); % plot the results