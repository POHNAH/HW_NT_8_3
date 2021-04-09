int choiceFlight(int roundTrip, int indexTypeSeat, char *types[], char *city1, char *city2)
{
	int i, j, k, indexRightTickets[4], priceRightTickets[4], count, price;
    char separators[] = ";";
    char *token;
	char paramName[100];
		
	lr_save_string(types[indexTypeSeat],"sPref");
	lr_save_string(lr_eval_string("{seatType}"),"sType");
	lr_save_string(city1,"c1");
	lr_save_string(city2,"c2");
	
	if (roundTrip == 0) {
		web_reg_save_param_ex(
		    "ParamName=outFlight", 
		    "LB/IC=name=\"outboundFlight\" value=\"",
		    "RB/IC=\"",
		    "Ordinal=all");
	
		web_submit_data("reservations.pl", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=depart", "Value={c1}", ENDITEM, 
			"Name=departDate", "Value={date1}", ENDITEM, 
			"Name=arrive", "Value={c2}", ENDITEM, 
			"Name=returnDate", "Value={date2}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=roundtrip", "Value=<OFF>", ENDITEM, 
			"Name=seatPref", "Value={sPref}", ENDITEM, 
			"Name=seatType", "Value={sType}", ENDITEM, 
			"Name=findFlights.x", "Value=72", ENDITEM, 
			"Name=findFlights.y", "Value=4", ENDITEM, 
			LAST);
		
		count = atoi(lr_eval_string("{outFlight_count}"));
		
		k = 0;
		for (i = 1; i <= count; i++) {
			sprintf(paramName, "{outFlight_%d}", i);
			
		    token = (char *)strtok(lr_eval_string(paramName), separators);
			token[strlen(token) - 1] = 0;
			token = (char *)strtok(NULL, separators);
			price = atoi(token);
	
			lr_output_message("Цена рейса %s равна: %d", lr_eval_string(paramName), price);
	
			if ((price >= 100) && (price <= 500)) {
				indexRightTickets[k] = i;
				priceRightTickets[k] = price;
				++k;
	   		}
		}
		
		if (k == 0) {
			lr_output_message("Нет рейсов с нужной ценой. Меняем класс билета.");
			return 1;
		}
		else {
			i = rand()%k;
			sprintf(paramName, "{outFlight_%d}", indexRightTickets[i]);
			lr_param_sprintf("outF", lr_eval_string(paramName));
			lr_output_message("Выбран рейс %s", lr_eval_string("{outF}"));
		}
		
		web_submit_form("reservations.pl_2", 
			"Snapshot=t5.inf", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={outF}", ENDITEM, 
			"Name=reserveFlights.x", "Value=3", ENDITEM, 
			"Name=reserveFlights.y", "Value=10", ENDITEM, 
			LAST);
	
		lr_save_string(lr_eval_string("{fName}"),"firstName");
		lr_save_string(lr_eval_string("{sName}"),"secondName");
		lr_save_string(lr_eval_string("{adress}"),"adr");
		lr_save_string(lr_eval_string("{home}"),"hom");
		lr_save_string(lr_eval_string("{cCard}"),"creditCard");
		lr_save_string(lr_eval_string("{cDate}"),"creditDate");
	
		web_submit_form("reservations.pl_3", 
			"Snapshot=t6.inf", 
			ITEMDATA, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={secondName}", ENDITEM, 
			"Name=address1", "Value={adr}", ENDITEM, 
			"Name=address2", "Value={hom}", ENDITEM, 
			"Name=pass1", "Value={firstName} {secondName}", ENDITEM, 
			"Name=creditCard", "Value={creditCard}", ENDITEM, 
			"Name=expDate", "Value={creditDate}", ENDITEM, 
			"Name=saveCC", "Value={randBoolean}", ENDITEM, 
			"Name=buyFlights.x", "Value=49", ENDITEM, 
			"Name=buyFlights.y", "Value=14", ENDITEM, 
			LAST);
		
	}
	else {
		web_reg_save_param_ex(
		    "ParamName=outFlight", 
		    "LB/IC=name=\"outboundFlight\" value=\"",
		    "RB/IC=\"",
		    "Ordinal=all");
		
		web_reg_save_param_ex(
		    "ParamName=returnFlight", 
		    "LB/IC=name=\"returnFlight\" value=\"",
		    "RB/IC=\"",
		    "Ordinal=all");
		
		web_submit_data("reservations.pl", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=depart", "Value={c1}", ENDITEM, 
			"Name=departDate", "Value={date1}", ENDITEM, 
			"Name=arrive", "Value={c2}", ENDITEM, 
			"Name=returnDate", "Value={date2}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=roundtrip", "Value=on", ENDITEM, 
			"Name=seatPref", "Value={sPref}", ENDITEM, 
			"Name=seatType", "Value={sType}", ENDITEM, 
			"Name=findFlights.x", "Value=72", ENDITEM, 
			"Name=findFlights.y", "Value=4", ENDITEM, 
			LAST);

		count = atoi(lr_eval_string("{outFlight_count}"));
		
		k = 0;
		for (i = 1; i <= count; i++) {
			sprintf(paramName, "{outFlight_%d}", i);
			
		    token = (char *)strtok(lr_eval_string(paramName), separators);
			token[strlen(token) - 1] = 0;
			token = (char *)strtok(NULL, separators);
			price = atoi(token);
	
			lr_output_message("Цена рейса %s равна: %d", lr_eval_string(paramName), price);
	
			if ((price >= 100) && (price <= 500)) {
				indexRightTickets[k] = i;
				priceRightTickets[k] = price;
				++k;
	   		}
		}
		
		if (k == 0) {
			lr_output_message("Нет рейсов с нужной ценой. Меняем класс билета.");
			return 1;
		}
		else {
			i = rand()%k;
			sprintf(paramName, "{outFlight_%d}", indexRightTickets[i]);
			lr_param_sprintf("outF", lr_eval_string(paramName));
			lr_output_message("Выбран рейс %s", lr_eval_string("{outF}"));
		}
		
		lr_save_string(lr_eval_string(lr_paramarr_random("returnFlight")),"randomTicket2");
	
		web_submit_form("reservations.pl_2", 
			"Snapshot=t5.inf", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={outF}", ENDITEM, 
			"Name=returnFlight", "Value={randomTicket2}", ENDITEM, 
			"Name=reserveFlights.x", "Value=3", ENDITEM, 
			"Name=reserveFlights.y", "Value=10", ENDITEM, 
			LAST);
	
		lr_save_string(lr_eval_string("{fName}"),"firstName");
		lr_save_string(lr_eval_string("{sName}"),"secondName");
		lr_save_string(lr_eval_string("{adress}"),"adr");
		lr_save_string(lr_eval_string("{home}"),"hom");
		lr_save_string(lr_eval_string("{cCard}"),"creditCard");
		lr_save_string(lr_eval_string("{cDate}"),"creditDate");
	
		web_submit_form("reservations.pl_3", 
			"Snapshot=t6.inf", 
			ITEMDATA, 
			"Name=firstName", "Value={firstName}", ENDITEM, 
			"Name=lastName", "Value={secondName}", ENDITEM, 
			"Name=address1", "Value={adr}", ENDITEM, 
			"Name=address2", "Value={hom}", ENDITEM, 
			"Name=pass1", "Value={firstName} {secondName}", ENDITEM, 
			"Name=creditCard", "Value={creditCard}", ENDITEM, 
			"Name=expDate", "Value={creditDate}", ENDITEM, 
			"Name=saveCC", "Value={randBoolean}", ENDITEM, 
			"Name=buyFlights.x", "Value=49", ENDITEM, 
			"Name=buyFlights.y", "Value=14", ENDITEM, 
			LAST);
	}
	return 0;
}
