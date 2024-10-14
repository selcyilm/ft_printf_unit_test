#include "unity.h"
#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

void	setUp()
{
}

void	tearDown()
{
}

void	write_to_file(const char *buf)
{
	FILE *file = freopen("output.txt", "w", stdout);

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}

	ft_printf(buf);

	fclose(file);

	freopen("/dev/tty", "w", stdout); // For Unix/Linux systems
}

void	write_to_file_int(const char *buf, int i)
{
	FILE *file = freopen("output.txt", "w", stdout);

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}

	ft_printf(buf, i);

	fclose(file);

	freopen("/dev/tty", "w", stdout); // For Unix/Linux systems
}

void	write_to_file_string(const char *buf, char *substr)
{
	FILE *file = freopen("output.txt", "w", stdout);

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}
	ft_printf(buf, substr);
	fclose(file);

	freopen("/dev/tty", "w", stdout); // For Unix/Linux systems
}

void	write_to_file_null(const char *buf)
{
	FILE *file = freopen("output.txt", "w", stdout);

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}
	char *s = NULL;
	ft_printf(buf, s);
	fclose(file);

	freopen("/dev/tty", "w", stdout); // For Unix/Linux systems
}

void	write_to_file_hex(const char *buf, unsigned int hex)
{
	FILE *file = freopen("output.txt", "w", stdout);

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}

	ft_printf(buf, hex);

	fclose(file);

	freopen("/dev/tty", "w", stdout); // For Unix/Linux systems
}

void	write_to_file_char(const char *buf, char c)
{
	FILE *file = freopen("output.txt", "w", stdout);

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}

	ft_printf(buf, c);

	fclose(file);

	freopen("/dev/tty", "w", stdout); // For Unix/Linux systems
}

void	write_to_file_ptr(const char *buf, void *p)
{
	FILE *file = freopen("output.txt", "w", stdout);

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}

	ft_printf(buf, p);

	fclose(file);

	freopen("/dev/tty", "w", stdout); // For Unix/Linux systems
}

void	write_to_file_ptr_printf(const char *buf, void *p)
{
	FILE *file = freopen("printf_output.txt", "w", stdout);

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}

	printf(buf, p);

	fclose(file);

	freopen("/dev/tty", "w", stdout); // For Unix/Linux systems
}

char	*read_from_file()
{
	FILE *file = fopen("output.txt", "r");

	if (file == NULL) {
		perror("Error opening file");
		return 0;
	}

	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	rewind(file);  // Reset the file pointer to the beginning

	char *buffer = (char *)malloc(file_size + 1);

	if (buffer == NULL) {
		perror("Memory allocation failed");
		fclose(file);
		return 0;
	}

	fread(buffer, 1, file_size, file);

	buffer[file_size] = '\0';

	fclose(file);
	//printf("|%s|\n", buffer);

	return (buffer);
}

char	*read_from_file_printf()
{
	FILE *file = fopen("printf_output.txt", "r");

	if (file == NULL) {
		perror("Error opening file");
		return 0;
	}

	fseek(file, 0, SEEK_END);
	long file_size = ftell(file);
	rewind(file);  // Reset the file pointer to the beginning

	char *buffer = (char *)malloc(file_size + 1);

	if (buffer == NULL) {
		perror("Memory allocation failed");
		fclose(file);
		return 0;
	}

	fread(buffer, 1, file_size, file);

	buffer[file_size] = '\0';

	fclose(file);
	//printf("|%s|\n", buffer);

	return (buffer);
}

void	clear_file_printf()
{
	FILE *file = fopen("printf_output.txt", "w");

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}

	fclose(file);
}

void	clear_file()
{
	FILE *file = fopen("output.txt", "w");

	if (file == NULL) {
		perror("Error opening file");
		return ;
	}

	fclose(file);
}

void	helper_with_ptr2(const char *str, void *p)
{
	write_to_file_ptr(str, p);
	char *actual = read_from_file();
	//printf("ft_printf: |%s|\n", actual);
	write_to_file_ptr_printf(str, p);
	char *expected = read_from_file_printf();
	//printf("printf: |%s|\n", expected);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(expected);
	free(actual);
	clear_file();
	clear_file_printf();
}

void	helper_no_arg(const char *str)
{
	write_to_file(str);
	char *actual = read_from_file();
	//printf("|%s|\n", actual);
	TEST_ASSERT_EQUAL_STRING(str, actual);
	free(actual);
	clear_file();
}

void	helper_with_int(char const *expected, const char *str, int num)
{
	write_to_file_int(str, num);
	char *actual = read_from_file();
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	clear_file();
}

void	helper_with_string(char const *expected, const char *str, char *substr)
{
	write_to_file_string(str, substr);
	char *actual = read_from_file();
	//printf("|%s|\n", actual);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	clear_file();
}

void	test_null_with_string(char const *expected, const char *str)
{
	write_to_file_null(str);
	char *actual = read_from_file();
	//printf("|%s|\n", actual);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	clear_file();
}

void	helper_with_hex(char const *expected, const char *str, unsigned int hex)
{
	write_to_file_hex(str, hex);
	char *actual = read_from_file();
	//printf("|%s|\n", actual);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	clear_file();
}

void	helper_with_char(char const *expected, const char *str, char c)
{
	write_to_file_char(str, c);
	char *actual = read_from_file();
	//printf("|%s|\n", actual);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	clear_file();
}

void	helper_with_ptr(char const *expected, const char *str, unsigned long p)
{
	write_to_file_char(str, p);
	char *actual = read_from_file();
	//printf("|%s|\n", actual);
	TEST_ASSERT_EQUAL_STRING(expected, actual);
	free(actual);
	clear_file();
}

void	test_no_arg()
{
	helper_no_arg("");
	helper_no_arg("hey");
	helper_no_arg("hello");
	helper_no_arg("howsitgoin");
	printf("\033[0;32mNO ARG TEST PASSED\033[0m\n");
}

void	test_int()
{
	helper_with_int("hello this is 42", "hello this is %d", 42);
	helper_with_int("negative case: -5", "negative case: %d", -5);
	helper_with_int("zero is: 0", "zero is: %d", 0);
	helper_with_int("large number: 2147483647", "large number: %d", 2147483647);
	helper_with_int("small negative number: -2147483648", "small negative number: %d", -2147483648);
	helper_with_int("just a string", "just a string", 0);
	helper_with_int("missing number: 42", "missing number: %d", 42);
	helper_with_int("", "", 0);
	printf("\033[0;32m%%d TEST PASSED\033[0m\n");

	helper_with_int("hello this is 42", "hello this is %i", 42);
	helper_with_int("negative case: -5", "negative case: %i", -5);
	helper_with_int("zero is: 0", "zero is: %i", 0);
	helper_with_int("large number: 2147483647", "large number: %i", 2147483647);
	helper_with_int("small negative number: -2147483648", "small negative number: %i", -2147483648);
	helper_with_int("just a string", "just a string", 0);
	helper_with_int("missing number: 42", "missing number: %i", 42);
	helper_with_int("", "", 0);
	printf("\033[0;32m%%i TEST PASSED\033[0m\n");

}

void	test_string()
{
	helper_with_string("hello this is 42", "hello this is %s", "42");
	helper_with_string("hello this is string", "hello this is %s", "string");
	helper_with_string("negative case: test", "negative case: %s", "test");
	helper_with_string("zero is: zero", "zero is: %s", "zero");
	helper_with_string("large string: a very long string that exceeds usual limits", "large string: %s", "a very long string that exceeds usual limits");
	helper_with_string("empty string: ", "empty string: %s", "");
	helper_with_string("null string: (null)", "null string: %s", NULL);
	helper_with_string("multiple words: hello world", "multiple words: %s", "hello world");
	helper_with_string("formatted string: test string", "formatted string: %s", "test string");
	test_null_with_string("(null)", "%s");
	printf("\033[0;32m%%s TEST PASSED\033[0m\n");
	
}	

void	test_hex()
{
	helper_with_hex("This is: f", "This is: %x", 15);
	helper_with_hex("Zero hex case: 0", "Zero hex case: %x", 0);
	helper_with_hex("Large hex number: 1ffffff", "Large hex number: %x", 33554431);
	helper_with_hex("Just a string", "Just a string", 0);
	helper_with_hex("Special hex characters: 2a", "Special hex characters: %x", 42);
	helper_with_hex("Formatted hex: deadbeef", "Formatted hex: %x", 3735928559);
	helper_with_hex("", "", 0);
	helper_with_hex("Hex of 255: ff", "Hex of 255: %x", 255);
	helper_with_hex("Hex of 16: 10", "Hex of 16: %x", 16);
	helper_with_hex("Large hex number: 7fffffff", "Large hex number: %x", 2147483647);
	helper_with_hex("Small hex number: 1", "Small hex number: %x", 1);
	helper_with_hex("Big number hex: 100000", "Big number hex: %x", 1048576);
	helper_with_hex("Hex of 1000: 3e8", "Hex of 1000: %x", 1000);
	helper_with_hex("Hex of 4096: 1000", "Hex of 4096: %x", 4096);
	helper_with_hex("Hex of 65535: ffff", "Hex of 65535: %x", 65535);
	helper_with_hex("Hex of 123456: 1e240", "Hex of 123456: %x", 123456);

	printf("\033[0;32m%%x TEST PASSED\033[0m\n");
	
	helper_with_hex("This is: F", "This is: %X", 15);
	helper_with_hex("Zero hex case: 0", "Zero hex case: %X", 0);
	helper_with_hex("Large hex number: 1FFFFFF", "Large hex number: %X", 33554431);
	helper_with_hex("Just a string", "Just a string", 0);
	helper_with_hex("Special hex characters: 2A", "Special hex characters: %X", 42);
	helper_with_hex("Formatted hex: DEADBEEF", "Formatted hex: %X", 3735928559);
	helper_with_hex("", "", 0);
	helper_with_hex("Hex of 255: FF", "Hex of 255: %X", 255);
	helper_with_hex("Hex of 16: 10", "Hex of 16: %X", 16);
	helper_with_hex("Large hex number: 7FFFFFFF", "Large hex number: %X", 2147483647);
	helper_with_hex("Small hex number: 1", "Small hex number: %X", 1);
	helper_with_hex("Big number hex: 100000", "Big number hex: %X", 1048576);
	helper_with_hex("Hex of 1000: 3E8", "Hex of 1000: %X", 1000);
	helper_with_hex("Hex of 4096: 1000", "Hex of 4096: %X", 4096);
	helper_with_hex("Hex of 65535: FFFF", "Hex of 65535: %X", 65535);
	helper_with_hex("Hex of 123456: 1E240", "Hex of 123456: %X", 123456);
	printf("\033[0;32m%%X TEST PASSED\033[0m\n");
}

void	test_char()
{
	helper_with_char("this is c", "this is %c", 'c');
	helper_with_char("this is ", "this is %c", 0);
	helper_with_char("", "", 0);
	helper_with_char("{", "%c", '{');
	helper_with_char("hello world", "hello worl%c", 'd');
	helper_with_char("???", "?%c?", '?');
	helper_with_char("", "", 'a');
	helper_with_char("", "", 'a');
	helper_with_char("", "", 'a');

	printf("\033[0;32m%%c TEST PASSED\033[0m\n");
}

void	test_ptr()
{
	void *ptr = NULL;
	helper_with_ptr2("%p", ptr);
	int	i = 12;
	helper_with_ptr2("%p", &i);
	char *str = "hello";
	helper_with_ptr2("%p", str);
	printf("\033[0;32m%%p TEST PASSED\033[0m\n");
	

}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_no_arg);
	RUN_TEST(test_int);
	RUN_TEST(test_string);
	RUN_TEST(test_hex);
	RUN_TEST(test_char);
	RUN_TEST(test_ptr);
	UNITY_END();
}
