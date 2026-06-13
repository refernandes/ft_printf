#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int	res_orig;
	int	res_sua;
	int	test_id;

	test_id = 1;
	printf("==================================================\n");
	printf("           INICIANDO TESTES COMPARATIVOS          \n");
	printf("==================================================\n\n");

	// --- TESTE 1: String Simples ---
	printf("[Teste %d] String simples sem especificadores:\n", test_id++);
	res_orig = printf("ORIGINAL: Olá Mundo, 42!\n");
	res_sua  = ft_printf("SUA     : Olá Mundo, 42!\n");
	printf("Retornos -> Original: %d | Seu: %d\n", res_orig, res_sua);
	printf("--------------------------------------------------\n\n");

	// --- TESTE 2: Caractere Único ---
	printf("[Teste %d] Especificador %%c simples:\n", test_id++);
	res_orig = printf("ORIGINAL: Caractere: [%c]\n", 'A');
	res_sua  = ft_printf("SUA     : Caractere: [%c]\n", 'A');
	printf("Retornos -> Original: %d | Seu: %d\n", res_orig, res_sua);
	printf("--------------------------------------------------\n\n");

	// --- TESTE 3: Caracteres Especiais / Limites ---
	printf("[Teste %d] Especificador %%c com nulo e quebra de linha:\n", test_id++);
	res_orig = printf("ORIGINAL: Nulo:[%c] Quebra:[%c]\n", '\0', '\n');
	res_sua  = ft_printf("SUA     : Nulo:[%c] Quebra:[%c]\n", '\0', '\n');
	printf("Retornos -> Original: %d | Seu: %d\n", res_orig, res_sua);
	printf("--------------------------------------------------\n\n");

	// --- TESTE 4: String Comum ---
	printf("[Teste %d] Especificador %%s simples:\n", test_id++);
	res_orig = printf("ORIGINAL: String: [%s]\n", "École 42 São Paulo");
	res_sua  = ft_printf("SUA     : String: [%s]\n", "École 42 São Paulo");
	printf("Retornos -> Original: %d | Seu: %d\n", res_orig, res_sua);
	printf("--------------------------------------------------\n\n");

	// --- TESTE 5: String Vazia ---
	printf("[Teste %d] Especificador %%s com string vazia:\n", test_id++);
	res_orig = printf("ORIGINAL: Vazia: [%s]\n", "");
	res_sua  = ft_printf("SUA     : Vazia: [%s]\n", "");
	printf("Retornos -> Original: %d | Seu: %d\n", res_orig, res_sua);
	printf("--------------------------------------------------\n\n");

// --- TESTE 6: Ponteiro Nulo (Edge Case clássico da 42) ---
	printf("[Teste %d] Conversores %%s com ponteiro NULL:\n", test_id++);
	char *str_null = NULL; // Criamos a variável aqui para o compilador não chiar
	res_orig = printf("ORIGINAL: [%s]\n", str_null);
	res_sua  = ft_printf("SUA     : [%s]\n", str_null);
	printf("Retornos -> Original: %d | Seu: %d\n", res_orig, res_sua);
	printf("--------------------------------------------------\n\n");

	// --- TESTE 7: Múltiplos Argumentos Combinados ---
	printf("[Teste %d] Múltiplos %%c e %%s misturados:\n", test_id++);
	res_orig = printf("ORIGINAL: Combo -> %c %s %c %s %c\n", '1', "dois", '3', "quatro", '5');
	res_sua  = ft_printf("SUA     : Combo -> %c %s %c %s %c\n", '1', "dois", '3', "quatro", '5');
	printf("Retornos -> Original: %d | Seu: %d\n", res_orig, res_sua);
	printf("--------------------------------------------------\n\n");

	// --- TESTE 8: Porcentagem Dupla ---
	// Nota: Como o seu parser atual ainda não trata %%, adicionei aqui para você lembrar de implementar!
	printf("[Teste %d] Escapando a porcentagem (%%%%):\n", test_id++);
	res_orig = printf("ORIGINAL: Progresso: 100%%\n");
	res_sua  = ft_printf("SUA     : Progresso: 100%%\n");
	printf("Retornos -> Original: %d | Seu: %d\n", res_orig, res_sua);
	printf("==================================================\n");

	return (0);
}
