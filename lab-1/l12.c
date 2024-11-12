int reverse(int arc){
	int rez = 0;
	while (arc > 0){
		rez = rez * 10;
		rez += arc %10;
		arc = arc / 10;
	}
	return rez / 10;
}
