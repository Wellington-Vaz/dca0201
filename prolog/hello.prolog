% isso eh um comentahrio
% ?- consult('hello.prolog').
% ?- ['hello.prolog'].
% enquanto o prolog estiver provando, mais de uma solucao
% poderah surgir. Se apenas uma solucao eh desejada, digite
% "." . Se mais de uma precisa ser avaliada, digite ";" para
% o interpretador continuar sua pesquisa.
%
%
% ?- trace.
% habilita a depuracao
% ?- nodebug.
% desabilita a depuracao
%

%homem(adao).
%homem(jose).
%gosta(pedro, maria).
%entregou(jose, livro, maria).

% familia simpson
homem(bart).
homem(homer).
mulher(marge).
mulher(lisa).
mulher(maggie).
pai(homer,bart).
pai(homer,lisa).
pai(homer,maggie).
pai(abraham, homer).
mae(marge,bart).
mae(marge,lisa).
mae(marge,maggie).

filho(X,Y) :- pai(Y,X).

nuclear(Filho, Pai, Mae) :- pai(Pai,Filho), mae(Mae,Filho).
% nuclar(bart, Pai, Mae) :- pai(Pai,bart), mae(Mae, bart).
neto(Neto,Avo):- pai(Avo,Pai), pai(Pai,Neto).

		    
