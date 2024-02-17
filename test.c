int main()
{
	int i = 0;
	while (++i < 50000)
		write(1, "1",1);
	return (0);
}
