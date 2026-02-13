%UNIVERSIDAD PEDAGOGICA Y TECNOLOGICA DE COLOMBIA
%INGENIERIA ELECTRONICA
%FACULTAD DE INGENIERIA
%COMUNICACIONES II

%LAB 1 CODIFICACIÓN HUFFMAN

% XIMENA CAROLINA CABIATIVA CEPSEDES
% JOSE DAVID CARREÑO PATIÑO
% BRAYAN ANYELO RODRIGUEZ LANCHEROS

%Codificación y Decodificación de Huffman.
%Creación de simbolos unicos y Probabilidades asignadas
Symbols = 1:10; 
Probabilidades = [.014 .015 .3 .3 .1 .1 .1 .015 .028 .028];
%----------------------------------------------------------
%Creación de diccionario con el comando "huffmandict"
Diccionario = huffmandict(Symbols,Probabilidades);
%----------------------------------------------------------
%Generamos el vector con el comando "randscr"
Vector = randsrc(100,1,[Symbols;Probabilidades]);
%----------------------------------------------------------
%Codificación de los símbolos aleatorios con el comando "huffmanenco"
Codificacion = huffmanenco(Vector,Diccionario);
%---------------------------------------------------------
%Decodificación de los datos para corroborar que coincidan con los
%originales
Decodificacion = huffmandeco(Codificacion,Diccionario);
isequal(Vector,Decodificacion)
%---------------------------------------------------------
%Conversión de la señal original a Binaria 
Signal_binary = de2bi(Vector);
%---------------------------------------------------------
%Determinamos la longitud de la señal
seqLen = numel(Signal_binary)
%---------------------------------------------------------
%Convertimos la señal codificada de Huffman 
binaryComp = de2bi(Codificacion);
%---------------------------------------------------------
%Determinamos la longitud de la señal
encodedLen = numel(binaryComp)
%---------------------------------------------------------

