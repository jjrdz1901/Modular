clc
clear all

 %%%%%%%%%%%%%%%%%%SEÑAL 100 NTERVALOS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
CicloSenalHIGH = [
165;178;172;161;157;164;170;163;180;148;128;222;575;589;522;578;577;424;272;198;214;
178;177;195;167;157;147;151;138;171;151;213;522;525;570;533;485;
584;444;283;198;198;171;181;157;136;145;148;153;149;141;341;453;
586;527;529;579;481;587;563;486;495;307;202;189;199;160;195;178;
184;182;178;209;409;598;562;578;549;600;615;560;599;431;282;192;
167;181;161;178;170;167;203;203;147;302;354;484;559;565;514;]

tHIGH=0.01:0.01:1

 figure(1)
 plot(tHIGH,CicloSenalHIGH)
 hold on
 grid on
 
 %%%%%%%%%%%%%%%%%%SEÑAL 100 NTERVALOS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



 %%%%%%%%%%%%%%%%%%SEÑAL1 30 NTERVALOS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 SenalCiclo1 = [
165;178;172;161;157;164;170;163;180;148;128;222;575;589;
522;578;577;424;272;198;214;178;177;195;167;157;147;151;138;171;
]
t1=0.01:0.01:0.3

 figure(2)
 plot(t1,SenalCiclo1)
 hold on
 grid on

 
 %%%%%%%%%%%%%%%%%%SEÑAL1 30 NTERVALOS%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

SenalCiclo2 = CicloSenalHIGH(31:60)
t2=0.01:0.01:0.3

 figure(3)
 plot(t2,SenalCiclo2)
 hold on
 grid on


SenalCiclo3 = CicloSenalHIGH(61:90)
t3=0.01:0.01:0.3

 figure(4)
 plot(t3,SenalCiclo3)
 hold on
 grid on

 
 
%Señales arbitrarias 
SenalCiclo4 = CicloSenalHIGH(61:90)/1.5
t4=0.01:0.01:0.3

 figure(10)
 plot(t4,SenalCiclo4)
 hold on
 grid on

t=0.01:0.01:0.3
y0 = sin(t)

figure(5);
plot(t,y0)
hold on
grid on



%1
x0 = cos(t);


figure(6);
plot(t,x0)
hold on
grid on





%Entradas

Entrada=[SenalCiclo1 SenalCiclo2 SenalCiclo3 SenalCiclo1 SenalCiclo2 SenalCiclo3 x0' y0']; %Entadas a la red
z=[1 1 1 1 1 1 -5 -5];

net = newff(Entrada,z);
[net,tr] = train(net,Entrada,z);

%z2=sim(net,Entrada);
%Test= [SenalCiclo1 SenalCiclo2 x0' y0' ];
z2=sim(net,Entrada)

