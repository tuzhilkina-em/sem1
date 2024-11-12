int conversion_to_binary(int vvd){
	int arc = 2;
	while (vvd > 0){
		arc = arc * 10;
		arc +=vvd % 2;
		vvd /= 2;
	}
	return arc;
}
