int my_strlen(const char *string)
{
	int len = 0;

	while (*string++)
		len++;
	return (len);
}
