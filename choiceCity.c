int choiceCity(int roundTrip, char *types[])
{
	int i, j, k;
	char *city1, *city2;
	
	i = rand()%3;
	city1 = lr_eval_string("{city}");
	city2 = lr_eval_string("{city}");
	
	k = 0;
	while (k < 3) {
		j = choiceFlight(roundTrip, i, types, city1, city2);
		if (j == 0) {
			return 0;
		}
		else {
			++k;
			--i;
			if (i < 0) {
				i = 0;
			}
		}
	}
	
	return 1;

}
