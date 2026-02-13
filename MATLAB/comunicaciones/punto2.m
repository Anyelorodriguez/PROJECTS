%Codificación y decodificación de Huffman con señal alfanumérica.

%Defina una señal alfanumérica en forma de matriz de células.
inputSig = {'a2',44,'a3',55,'a1'}
%Defina un diccionario (los códigos para las letras de señales deben ser numéricos)
dict = {'a1',0; 'a2',[1,0]; 'a3',[1,1,0]; 44,[1,1,1,0]; 55,[1,1,1,1]}
%Codifique los símbolos alfanuméricos
enco = huffmanenco(inputSig,dict)
%Decodifique los datos y verifique que los datos decodificados coincidan con los datos originales.
sig = huffmandeco(enco,dict)
%ve si son iguales
isequal(inputSig,sig)