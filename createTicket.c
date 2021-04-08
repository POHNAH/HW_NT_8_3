createTicket()
{	
	int randomNumber, i, k;
    char separators[] = "\n";
    char *token;
    char *types[3];
	char paramName[100];

//	собираем все типы билетов
    lr_read_file("type.dat", "t", 0);
    token = (char *)strtok(lr_eval_string("{t}"),separators);
	i = 0;
    while (token != NULL ) {
		token[strlen(token) - 1] = 0;
		types[i] = token;
		token = (char *)strtok(NULL, separators);
        ++i;
    }
	
	randomNumber = rand()%2;

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	k = 1;
    while (k == 1) {
	    k = choiceCity(randomNumber, types);    	
    }

	return 0;
}
