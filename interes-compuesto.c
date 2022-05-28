#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	//	VARIABLES
	double tOper, rOper, cfOper, ciOper;
	double cfResul[5], tempCFResul, cfRCapIni[5], tempCFRCapIni, cfRInte[5], tempCFRInte, cfRTiem[5], tempCFRTiem;
	double ciResul[5], tempCIResul, ciRCapFin[5], tempCIRCapFin, ciRInte[5], tempCIRInte, ciRTiem[5], tempCIRTiem;
	double rResul[5], tempRResul, rRCapFin[5], tempRRCapFin, rRCapIni[5], tempRRCapIni, rRTiem[5], tempRRTiem;
	double tResul[5], tempTResul, tRCapFin[5], tempTRCapFin, tRCapIni[5], tempTRCapIni, tRInte[5], tempTRInte;

	int opcion, outer, inner, didSwap, cfI=0, ciI=0, rI=0, tI=0, icfI, iciI, irI, itI;

	// ARCHIVO
	FILE *listas;
	char filename[500];
	strcpy(filename, "resultados-interes-compuesto.txt");
	listas = fopen(filename, "w");
	
	
	//	BUBBLE SORT
	// SORT CAPITAL FINAL
	for(outer=0; outer<4; outer++)
    {
        didSwap=0;
        for(inner=outer; inner<5; inner++)
        {
            if(cfResul[inner]>cfResul[outer])
            {
                tempCFResul=cfResul[inner];
                tempCFRCapIni=cfRCapIni[inner];
				tempCFRInte=cfRInte[inner];
				tempCFRTiem=cfRTiem[inner];
                
                cfResul[inner]=cfResul[outer];
                cfRCapIni[inner]=cfRCapIni[outer];
				cfRInte[inner]=cfRInte[outer];
				cfRTiem[inner]=cfRTiem[outer];
                
                cfResul[outer]=tempCFResul;
                cfRCapIni[outer]=tempCFRCapIni;
				cfRInte[outer]=tempCFRInte;
				cfRTiem[outer]=tempCFRTiem;
                
                didSwap=1;
            }
        }
        if(didSwap==0)
        {
            break;
        }
    }

	//	SORT CAPITAL INICIAL
	for(outer=0; outer<4; outer++)
    {
        didSwap=0;
        for(inner=outer; inner<5; inner++)
        {
            if(ciResul[inner]>ciResul[outer])
            {
                tempCIResul=ciResul[inner];
                tempCIRCapFin=ciRCapFin[inner];
				tempCIRInte=ciRInte[inner];
				tempCIRTiem=ciRTiem[inner];
                
                ciResul[inner]=ciResul[outer];
                ciRCapFin[inner]=ciRCapFin[outer];
				ciRInte[inner]=ciRInte[outer];
				ciRTiem[inner]=ciRTiem[outer];
                
                ciResul[outer]=tempCIResul;
                ciRCapFin[outer]=tempCIRCapFin;
				ciRInte[outer]=tempCIRInte;
				ciRTiem[outer]=tempCIRTiem;
                
                didSwap=1;
            }
        }
        if(didSwap==0)
        {
            break;
        }
    }

	//	SORT INTERES
	for(outer=0; outer<4; outer++)
    {
        didSwap=0;
        for(inner=outer; inner<5; inner++)
        {
            if(rResul[inner]>rResul[outer])
            {
                tempRResul=rResul[inner];
                tempRRCapFin=rRCapFin[inner];
				tempRRCapIni=rRCapIni[inner];
				tempRRTiem=rRTiem[inner];
                
                rResul[inner]=rResul[outer];
                rRCapFin[inner]=rRCapFin[outer];
				rRCapIni[inner]=rRCapIni[outer];
				rRTiem[inner]=rRTiem[outer];
                
                rResul[outer]=tempRResul;
                rRCapFin[outer]=tempRRCapFin;
				rRCapIni[outer]=tempRRCapIni;
				rRTiem[outer]=tempRRTiem;
                
                didSwap=1;
            }
        }
        if(didSwap==0)
        {
            break;
        }
    }

	//	SORT TIEMPO
	for(outer=0; outer<4; outer++)
    {
        didSwap=0;
        for(inner=outer; inner<5; inner++)
        {
            if(tResul[inner]>tResul[outer])
            {
                tempTResul=tResul[inner];
                tempTRCapFin=tRCapFin[inner];
				tempTRInte=tRInte[inner];
				tempTRCapIni=tRCapIni[inner];
                
                tResul[inner]=tResul[outer];
                tRCapFin[inner]=tRCapFin[outer];
				tRInte[inner]=tRInte[outer];
				tRCapIni[inner]=tRCapIni[outer];
                
                tResul[outer]=tempTResul;
                tRCapFin[outer]=tempTRCapFin;
				tRInte[outer]=tempTRInte;
				tRCapIni[outer]=tempTRCapIni;
                
                didSwap=1;
            }
        }
        if(didSwap==0)
        {
            break;
        }
    }


	//	BUCLE
	do{
		//	MENU
		printf("Elige una opcion del menu de acuerdo a la operacion que desees realizar:\n\nCAPITAL FINAL: 1\nCAPITAL INICIAL: 2\nINTERES: 3\nTIEMPO: 4\nSALIR: 5\n\nELIGE TU OPCION: ");
		scanf("%d", &opcion);
		switch(opcion)
		{
			case 1:
				//	OUTPUT
				printf("Formula para hallar el capital final: cf=ci*(1+r)^t\n\n");
				printf("Ingresa el capital inicial:\n");
				scanf(" %lf", &ciOper);
				printf("Ingresa el interes: \n");
				scanf(" %lf", &rOper);
				printf("Ingresa el tiempo: \n");
				scanf(" %lf", &tOper);
				
				//	OPERATION
				cfRCapIni[cfI]=ciOper;
				cfRInte[cfI]=rOper;
				cfRTiem[cfI]=tOper;
				
				//	CALCULO
				cfOper=ciOper*(pow((1+rOper), tOper));
				printf("El resultado del capital final es igual a: %.6lf\n\n", cfOper);
                cfResul[cfI]=cfOper;
                cfI++;
			

				break;
				
				
			case 2:
				//	OUTPUT
				printf("Formula para hallar el capital inicial: ci=cf/((1+r)^t)\n\n");
				printf("Ingresa el capital final: \n");
				scanf(" %lf", &cfOper);
				printf("Ingresa el interes: \n");
				scanf(" %lf", &rOper);
				printf("Ingresa el tiempo: \n");
				scanf(" %lf", &tOper);
				
				//	OPERATION
                ciRCapFin[ciI]=cfOper;
                ciRInte[ciI]=rOper;
                ciRTiem[ciI]=tOper;

				//	CALCULO
				ciOper=cfOper/(pow((1+rOper), tOper));
				printf("El resultado del capital inicial es igual a: %.6lf\n\n", ciOper);
				ciResul[ciI]=ciOper;
                ciI++;

				break;
				
				
			case 3:
				//	OUTPUT
				printf("Formula para hallar el interes: r=((cf/ci)^(1/t))-1\n\n");
				printf("Ingresa el capital final: \n");
				scanf(" %lf", &cfOper);
				printf("Ingresa el capital inicial: \n");
				scanf(" %lf", &ciOper);
				printf("Ingresa el tiempo: \n");
				scanf(" %lf", &tOper);
				
				//	OPERATION
                rRCapFin[rI]=cfOper;
                rRCapIni[rI]=ciOper;
                rRTiem[rI]=tOper;

				//	CALCULO
				// interes=(sqrt((cf/ci), tiempo))-uno;				
				rOper=(pow((cfOper/ciOper), (1/tOper)))-1;
				
				printf("El resultado del interes es igual a: %.3lf\n\n", rOper);
				rResul[rI]=rOper;
                rI++;

				break;
				
				
			case 4:
				//	OUTPUT
				printf("Formula para hallar el tiempo: t=(((log(cf))-(log(ci)))/(log(1+r)))\n\n");
				printf("Ingresa el capital final: \n");
				scanf(" %lf", &cfOper);
				printf("Ingresa el capital inicial: \n");
				scanf(" %lf", &ciOper);
				printf("Ingresa el interes: \n");
				scanf(" %lf", &rOper);
				
				//	OPERATION
                tRCapFin[tI]=cfOper;
                tRCapIni[tI]=ciOper;
                tRInte[tI]=rOper;

				//	CALCULO
				tOper=(((log(cfOper))-(log(ciOper)))/(log(1+rOper)));
				printf("El resultado del tiempo es igual a: %.1lf\n\n", tOper);
                tResul[tI]=tOper;
                tI++;

				break;

			case 5:
				printf("\nSales del programa.\n\n\n");
				break;
				
				
			default:
				printf("Por favor escriba un valor correcto.\n");
		}
	}
	
	while(opcion!=5);

    //  PRE-BUCLE
    icfI=cfI;
    iciI=ciI;
    irI=rI;
    itI=tI;

	//////////////////////////////////////////////

	//  BUCLE PARA IMPRIMIR LOS ARRAYS EN CONSOLA
	for(cfI=0; cfI<icfI; cfI++)
    {
        printf("El resulta del capital final N%d es: %.6lf\n", cfI+1, cfResul[cfI]);
		printf("%.6lf=%.2lf*(1+%.3lf)^%.0lf\n", cfResul[cfI], cfRCapIni[cfI], cfRInte[cfI], cfRTiem[cfI]);
    }	
	printf("\n\n");
    
	
	for(ciI=0; ciI<iciI; ciI++)
    {
        printf("El resulta del capital inicial N%d es: %.2lf\n", ciI+1, ciResul[ciI]);
		printf("%.2lf=%.6lf/((1+%.3lf)^%.0lf)\n", ciResul[ciI], ciRCapFin[ciI], ciRInte[ciI], ciRTiem[ciI]);
    }	
	printf("\n\n");

    
	for(rI=0; rI<irI; rI++)
    {
        printf("El resulta del interes N%d es: %.3lf\n", rI+1, rResul[rI]);
		printf("%.3lf=((%.6lf/%.2lf)^(1/%.0lf))-1\n", rResul[rI], rRCapFin[rI], rRCapIni[rI], rRTiem[rI]);
    }	
	printf("\n\n");

    
	for(tI=0; tI<itI; tI++)
    {
        printf("El resulta del tiempo N%d es: %.2lf\n", tI+1, tResul[tI]);
		printf("%.0lf=(((log(%.6lf))-(log(%.2lf)))/(log(1+%.3lf)))\n", tResul[tI], tRCapFin[tI], tRCapIni[tI], tRInte[tI]);
    }
	



	//  BUCLE PARA IMPRIMIR LOS ARRAYS EN ARCHIVO.TXT
	for(cfI=0; cfI<icfI; cfI++)
    {
        fprintf(listas, "El resulta del capital final N%d es: %.6lf\n", cfI+1, cfResul[cfI]);
		fprintf(listas, "%.6lf=%.2lf*(1+%.3lf)^%.0lf\n", cfResul[cfI], cfRCapIni[cfI], cfRInte[cfI], cfRTiem[cfI]);
    }	
	fprintf(listas, "\n");
    
	
	for(ciI=0; ciI<iciI; ciI++)
    {
        fprintf(listas, "El resulta del capital inicial N%d es: %.2lf\n", ciI+1, ciResul[ciI]);
		fprintf(listas, "%.2lf=%.6lf/((1+%.3lf)^%.0lf)\n", ciResul[ciI], ciRCapFin[ciI], ciRInte[ciI], ciRTiem[ciI]);
    }	
	fprintf(listas, "\n");

    
	for(rI=0; rI<irI; rI++)
    {
        fprintf(listas, "El resulta del interes N%d es: %.3lf\n", rI+1, rResul[rI]);
		fprintf(listas, "%.3lf=((%.6lf/%.2lf)^(1/%.0lf))-1\n", rResul[rI], rRCapFin[rI], rRCapIni[rI], rRTiem[rI]);
    }	
	fprintf(listas, "\n");

    
	for(tI=0; tI<itI; tI++)
    {
        fprintf(listas, "El resulta del tiempo N%d es: %.2lf\n", tI+1, tResul[tI]);
		fprintf(listas, "%.0lf=(((log(%.6lf))-(log(%.2lf)))/(log(1+%.3lf)))\n", tResul[tI], tRCapFin[tI], tRCapIni[tI], tRInte[tI]);
    }
	
	
	fprintf(listas, "\n");
	
	return 0;
}