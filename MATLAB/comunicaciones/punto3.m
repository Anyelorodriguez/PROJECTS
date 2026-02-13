%UNIVERSIDAD PEDAGOGICA Y TECNOLOGICA DE COLOMBIA
%INGENIERIA ELECTRONICA
%FACULTAD DE INGENIERIA
%COMUNICACIONES II

%LAB 1 CODIFICACIÓN HUFFMAN

% XIMENA CAROLINA CABIATIVA CEPSEDES
% JOSE DAVID CARREÑO PATIÑO
% BRAYAN ANYELO RODRIGUEZ LANCHEROS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Script en Matlab para calcular el código 
k=1;
caracteres(k)=0;clc
texto='oscarvera';
for i=32:225 %representacion ASCII para el alfabeto y numeros
    dato=char(i); 
    total=length(strfind(texto,dato)); 
    probabilidad(k)=total/length(texto);%la proba es total sobre la longitud del texto
    if (total~=0)
        caracteres(k)=total;%almacena en vector el valor de "total"
        fprintf('Caracter:\t%c se repitio:\t%d veces ',dato,total);%el char se repite entero veces 
        fprintf('con probabilidad\t%f\n',probabilidad(k));%% imprime la probabilidad
        k=k+1;%%aumenta contador para probabilidad
    end
end
 
fprintf('Codigo Huffman');
simbolo=1:length(probabilidad)-1;       %genera simbolos para crear el diccionario de palabras, se toma "prob" porque ahí está cada carácter inicial 
probabilidad=probabilidad(1:length(simbolo)); %Probabilidad de cada caracter
 
dict = huffmandict(simbolo,probabilidad); % Crea el diccionario
for i=1:length(simbolo) %%recorrido de 1 hasta el tamaño total del texto ingresado
       dict{i,:}% Muestra una fila del diccionario
end
%%%% 
