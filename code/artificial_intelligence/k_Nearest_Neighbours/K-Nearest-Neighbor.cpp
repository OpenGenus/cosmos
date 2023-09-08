#include<iostream>
#include<conio.h>
#include <string.h>
#include <fstream>
#include <sstream>
using namespace std;
int main()
{
	
	int i, j, l;
	int tsc = 200;

	int preg[200];
	int plus[200];
	int pres[200];
	int skin[200];
	int insu[200];
	float mass[200];
	float pedi[200];
	int age[200];
	char *Class[200];
	for (int h = 0; h < 200; h++)
	{
		Class[h] = new char[20];
		//Class[h][] = "\0";
	}


	ifstream load;
	int h;
	load.open("Dataset.txt");
	if (!load)
	{
		cerr << "file opening error...";
			exit(0);
	}
	else
	{
		string file;
		stringstream read;

		while (!load.eof())
		{
			for (int y = 0; y < 200; y++)
			{
				 
					read.str("");
					read.clear();

					getline(load, file);
					{
						read << file;
						read >> preg[y];
						read >> plus[y];
						read >> pres[y];
						read >> skin[y];
						read >> insu[y];
						read >> mass[y];
						read >> pedi[y];
						read >> age[y];
						read >> Class[y];
					
				}
			}
		}
		}
	
	
	float pos = 0.0;
	float neg = 0.0;

	for (int y = 0; y < 200; y++)
	{
		if (strcmp(Class[y], "tested_positive") == 0)
		{
			pos++;
		}
		else if(strcmp(Class[y],"tested_negative")==0)
		{
			neg++;
		}
	}

	int medium = 0;
	/*for (int i = 0; i<20; i++)
	{
		if (strcmp(op[i], "short") == 0)
		{
			Short++;
		}
		else if (strcmp(op[i], "medium") == 0)
		{
			medium++;
		}
		else
		{
			tall++;
		}
	}*/

	//cout << Short << " " << medium << " " << tall;

	cout << endl << "*******************************  K--Nierest Neighbour  **********************************" << endl << endl;


	cout << "\n \tInitial Set:   Diabeties" << endl;
	cout << "\n\tpreg\tplus\tpres\tskin\tinsu\tmass\tpedi\tage\tTest Result";
	for (i = 0; i<200; i++)
	{
		cout << "\n\t" << preg[i] << "\t" << plus[i] << "\t" << pres[i]<<"\t"<<skin[i]<<"\t"<<insu[i]<<"\t"<<mass[i]<<"\t"<<pedi[i]<<"\t"<<age[i]<<"\t"<<Class[i];
	}




	int prg;
	int pls;
	int prs;
	int skn;
	int ins;
	float mas;
	float ped;
	int ag;
	
	char ng;
	cout << endl << "\n Enter tuple to be processed (preg,plus,pres,skin,insu,mass,pedi,age,Class) :";
	cin >> prg>> pls >> prs >> skn >> ins >> mas >> ped >> ag;

	int t;
	cout << "\n Enter threshold:";
	cin >> t;

	int preg_s[200][2], k;
	int plus_s[200][2];
	int pres_s[200][2];
	int skin_s[200][2];
	int insu_s[200][2];
	float mass_s[200][2];
	float pedi_s[200][2];
	int age_s[200][2];
	
	//calculating distance to each value in training set
	for (i = 0; i<200; i++)
	{
		preg_s[i][0] = i;
		//k = h[i] - nh;
		k = preg[i] - prg;
		if (k<0)
		{
			preg_s[i][1] = -k;
		}
		else
		{
			preg_s[i][1] = k;
		}
	}

	//Sorting
	for (i = 0; i<199; i++)
	{
		for (j = 0; j<199; j++)
		{
			if (preg_s[j][1]>preg_s[j + 1][1])
			{
				k = preg_s[j][1];
				preg_s[j][1] = preg_s[j + 1][1];
				preg_s[j + 1][1] = k;

				l = preg_s[j][0];
				preg_s[j][0] = preg_s[j + 1][0];
				preg_s[j + 1][0] = l;
			}
		}
	}

	//calculating distance to each value in training set
	for (i = 0; i<200; i++)
	{
		plus_s[i][0] = i;
		//k = h[i] - nh;
		k = plus[i] - pls;
		if (k<0)
		{
			plus_s[i][1] = -k;
		}
		else
		{
			plus_s[i][1] = k;
		}
	}

	//Sorting
	for (i = 0; i<199; i++)
	{
		for (j = 0; j<199; j++)
		{
			if (plus_s[j][1]>plus_s[j + 1][1])
			{
				k = plus_s[j][1];
				plus_s[j][1] = plus_s[j + 1][1];
				plus_s[j + 1][1] = k;

				l = plus_s[j][0];
				plus_s[j][0] = plus_s[j + 1][0];
				plus_s[j + 1][0] = l;
			}
		}
	}


	//calculating distance to each value in training set
	for (i = 0; i<200; i++)
	{
		pres_s[i][0] = i;
		//k = h[i] - nh;
		k = pres[i] - prs;
		if (k<0)
		{
			pres_s[i][1] = -k;
		}
		else
		{
			pres_s[i][1] = k;
		}
	}

	//Sorting
	for (i = 0; i<199; i++)
	{
		for (j = 0; j<199; j++)
		{
			if (pres_s[j][1]>pres_s[j + 1][1])
			{
				k = pres_s[j][1];
				pres_s[j][1] = pres_s[j + 1][1];
				pres_s[j + 1][1] = k;

				l = pres_s[j][0];
				pres_s[j][0] = pres_s[j + 1][0];
				pres_s[j + 1][0] = l;
			}
		}
	}
	


	//calculating distance to each value in training set
	for (i = 0; i<200; i++)
	{
		skin_s[i][0] = i;
		//k = h[i] - nh;
		k = skin[i] - skn;
		if (k<0)
		{
			skin_s[i][1] = -k;
		}
		else
		{
			skin_s[i][1] = k;
		}
	}

	//Sorting
	for (i = 0; i<199; i++)
	{
		for (j = 0; j<199; j++)
		{
			if (skin_s[j][1]>skin_s[j + 1][1])
			{
				k = skin_s[j][1];
				skin_s[j][1] = skin_s[j + 1][1];
				skin_s[j + 1][1] = k;

				l = skin_s[j][0];
				skin_s[j][0] = skin_s[j + 1][0];
				skin_s[j + 1][0] = l;
			}
		}
	}



	//calculating distance to each value in training set
	for (i = 0; i<200; i++)
	{
		insu_s[i][0] = i;
		//k = h[i] - nh;
		k = insu[i] - ins;
		if (k<0)
		{
			insu_s[i][1] = -k;
		}
		else
		{
			insu_s[i][1] = k;
		}
	}

	//Sorting
	for (i = 0; i<199; i++)
	{
		for (j = 0; j<199; j++)
		{
			if (insu_s[j][1]>insu_s[j + 1][1])
			{
				k = insu_s[j][1];
				insu_s[j][1] = insu_s[j + 1][1];
				insu_s[j + 1][1] = k;

				l =insu_s[j][0];
				insu_s[j][0] = insu_s[j + 1][0];
				insu_s[j + 1][0] = l;
			}
		}
	}



	//calculating distance to each value in training set
	for (i = 0; i<200; i++)
	{
		mass_s[i][0] = i;
		//k = h[i] - nh;
		k = mass[i] - mas;
		if (k<0)
		{
			mass_s[i][1] = -k;
		}
		else
		{
			mass_s[i][1] = k;
		}
	}

	//Sorting
	for (i = 0; i<199; i++)
	{
		for (j = 0; j<199; j++)
		{
			if (mass_s[j][1]>mass_s[j + 1][1])
			{
				k = mass_s[j][1];
				mass_s[j][1] = mass_s[j + 1][1];
				mass_s[j + 1][1] = k;

				l = mass_s[j][0];
				mass_s[j][0] = mass_s[j + 1][0];
				mass_s[j + 1][0] = l;
			}
		}
	}




	//calculating distance to each value in training set
	for (i = 0; i<200; i++)
	{
		pedi_s[i][0] = i;
		//k = h[i] - nh;
		k = pedi[i] - ped;
		if (k<0)
		{
			pedi_s[i][1] = -k;
		}
		else
		{
			pedi_s[i][1] = k;
		}
	}

	//Sorting
	for (i = 0; i<199; i++)
	{
		for (j = 0; j<199; j++)
		{
			if (pedi_s[j][1]>pedi_s[j + 1][1])
			{
				k = pedi_s[j][1];
				pedi_s[j][1] = pedi_s[j + 1][1];
				pedi_s[j + 1][1] = k;

				l = pedi_s[j][0];
				pedi_s[j][0] = pedi_s[j + 1][0];
				pedi_s[j + 1][0] = l;
			}
		}
	}




	//calculating distance to each value in training set
	for (i = 0; i<200; i++)
	{
		age_s[i][0] = i;
		//k = h[i] - nh;
		k = age[i] - ag;
		if (k<0)
		{
			age_s[i][1] = -k;
		}
		else
		{
			age_s[i][1] = k;
		}
	}

	//Sorting
	for (i = 0; i<199; i++)
	{
		for (j = 0; j<199; j++)
		{
			if (age_s[j][1]>age_s[j + 1][1])
			{
				k = age_s[j][1];
				age_s[j][1] = age_s[j + 1][1];
				age_s[j + 1][1] = k;

				l = age_s[j][0];
				age_s[j][0] = age_s[j + 1][0];
				age_s[j + 1][0] = l;
			}
		}
	}

	float nos = 0.0;  //no of shorts
	float nom = 0.0;  //no of mediums
	int ot = 0;  //no of talls


//for(int h=0;h;<t;h++)
	cout << "\npreg\tplus\tpres\tskin\tinsu\tmass\tpedi\tage\tOutput\n";
	for (i = 0; i < t; i++)
	{
		int l8 = age_s[i][0];
		int l1 = preg_s[i][0];
		int l2 = plus_s[i][0];
		int l3 = pres_s[i][0];
		int l4 = skin_s[i][0];
		int l5 = insu_s[i][0];
		int l6 = pedi_s[i][0];
		int l7 = mass_s[i][0];
		
		cout << preg[l1]<<"\t"<<plus[l2]<<"\t"<<pres[l3]<<"\t"<<skin[l4]<<"\t"<<insu[l5]<<"\t"<<pedi[l6]<<"\t"<<mass[l7]<<"\t"<<age[l8]<<"\t"<<Class[l1]<<endl ;
	
		if (strcmp(Class[l1], "tested_positive") == 0)
		{
			nos++;
		}
		if (strcmp(Class[l1], "tested_negative") == 0)
		{
			nom++;
		}
	}
	float total = pos + neg;
	//cout << pos <<" "<< neg;
	cout << "\n No of positive tests:" << nos;
	cout << "\n No of negative tests:" << nom;
	
	float p1, n1;
	p1 = pos - nos;
	n1 = neg - nom;

	//m = medium - nom;
	//t1 = tall - ot;
	if (nos>nom&&nos>ot)
	{
		cout << endl << "\n New Tuple is classified as Positive";
	}

	if (nom>nos&&nom>ot)
	{
		cout << endl << "\n New Tuple is classified as Negetive";
	}

	if (ot>nom&&ot>nos)
	{
		cout << endl << "\n New Tuple is classified as Tall";
	}
	float FP= neg - nom;
	float TN= pos - nos;
    float FN= nom;
	float TP= nos;

	//cout << "FP: " << neg - nom;
	//cout << " TN: " << pos - nos;
	//cout << "FN: " << nom;
//	cout << "TP: " << nos;
	cout << endl <<endl<< endl<<endl<<endl << "\t\t **********RESULTS*********" << endl << endl<<endl;

	cout << "*.Total number of Instances: " << pos + neg<<endl;
	cout << "*.Correctly Classified Classes: " << nos + nom<<endl;
	cout << "*.In-Correctly Classifeid Classes: " << p1 + n1<<endl<<endl<<endl;
	cout << "          =====Confusion Matrix=====" << endl<<endl;
	cout << "                       Predicted Positive_tested\t   Predicted Negetive_tested" << endl;
	cout << " Actual Positive_tested          " << TP << "\t\t\t\t\t"<<TN<<endl;
	cout << " Actual Negetive_tested          "<<FP<<"\t\t\t\t\t"<<FN;
	cout << endl<<endl<<endl<<endl;
	cout << "            =====Detailed Accuracy by Class=====" << endl << endl << endl;
	float Accuracy = (TP + TN) / total;
	float Misclassification_Rate = (FP + FN) / total;
	float  TP_Rate = TP / pos;
	float FP_Rate = FP / neg;
	float speci = TN / neg;
	float Preci = TP / pos;
	float Prevalence = pos / total;
	cout << "Accuracy\tError_Rate\tRecall/TP_rate\t   FP_rate     \tSpecitivity\tPrecision\tPrevalence" << endl<<endl;
	cout << " "<<Accuracy << "\t\t    " << Misclassification_Rate << "\t     " << TP_Rate << "\t            " << FP_Rate << "           \t" << speci << "\t" << Preci << "\t" << Prevalence;
		_getche();
}
