clear all
close all
clc
%Entradas
A=[0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1];
B=[0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0 0 1 1 0];

Entrada=[A;B]; %Entadas a la red
Y=[0 3 3 3 0 3 3 3 0 3 3 3 0 3 3 3 0 3 3 3 0 3 3 3]; % Salida deseada

% pesosInciales = [-1.2];
% bias =[-1.5];

net = newff(Entrada,Y);
[net,tr] = train(net,Entrada,Y);

% net = newp([0 1; 0 1],1); %Red perceptron de 1 neurona con dos entradas
% % net.iw{1}=pesosIniciales;
% % net.b{1}=bias;
% net.trainParam.epochs =100; %Iteraciones de entrenamiento
% net =train(net,Entrada,Y);
A1=[1 0 0 1];
B1=[1 0 0 0];
z2=sim(net,[A1;B1])

%getwb(net)

wb = formwb(net,net.b,net.iw,net.lw)
[b,iw,lw] = separatewb(net,wb)



