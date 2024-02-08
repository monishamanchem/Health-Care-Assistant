/*---------------------------------README-----------------------------------------------
This is a Desktop Healthcare Assistant Program, which allows user to, 
    1.Register Account
    2.Buy Product
    3.Create Home Workout Planner(for 4 weeks)
    4.Display Quick Remedies
    5.Display User's Account Info

******NOTE:
        Before running the Program please ensure that the files, "ItemsName.txt", and
        the folder "REMEDIES", exist in the same folder where the code is present.
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>


void Register();
int Login();
int main_screen();
void Loader();
int spaces(int p);
void returnfunc();
int lines_in_file(FILE * fp);
void align_spaces(char *ptr);
void ecommerce();
int View_items();
void View_cart();
int checkout();
int payment();
void otp_screen();
int display_planner(int *dts, char *lvl);
int workoutPlanner();
void remedies();
void accountinfo();
void exit_screen();
void Timestamp();

struct item{
    int id;
    char item_name[50];
    float price;
};


void sleep(unsigned int mseconds) 
{
    clock_t goal = mseconds + clock();  //clock_t is not a primitive datatype
    while (goal > clock());
}
int spaces(int p){
    int q;
    for(q=0;q<p;q++){
        printf(" ");
    }
    return 0;
}

float Calculate_BMI(float *weight, float *height) {
   float bmi;
   bmi=(*weight)/(pow(*height,2));
   return bmi;
}

//this function displays a screen which shows loading animation
void Loader(){  
	int loader;
	system("cls");
	printf("LOADING........");
	printf("\n\n"); 
	for(loader=1;loader<20;loader++){
		sleep(100); // 1second = 1000millisecond
		printf("%c",219); //after each second one small block will get added
	}
}
void returnfunc(){
    if(getch()==13){ //allows only input of enter
        main_screen();
    }
    else{
        returnfunc();
    }
}
//this function tells the number of lines in a file
int lines_in_file(FILE * fp){
    int count_lines=0;
    char chr;
    chr= getc(fp);// characters of the file are stored in chr
    while(chr != EOF){
        if(chr=='\n'){
            count_lines+=1;
        }
        chr=getc(fp);//to get next char from file
    }
    count_lines+=1;//we did this because, we may not end the last line of a file by pressing enter key;
    return count_lines;
}
int date_today(){
    int date_int;
    time_t rawtime;

    time ( &rawtime );
    char temp[50];
    strcpy(temp, ctime (&rawtime));//here ctime is used so that we can get &rawtime in string data type
    char word[100];
    char date[3]; 
    int i=0,k=0;
    strncpy(word, temp, 100); // the strncpy function copies the first n characters of the array 'temp' into the array 'word'
        while(word[i]!='\0'){ 
        if(i==8 || i==9){
            date[k]=word[i];
            k++;
        }
        i++; 
    } 
    date_int=atoi(date);
    return date_int;
}
int payment(){
	int card_num,mm,yy,cvv;
    system("cls");
    printf("\n-----------------------------------------------------");
    spaces(20);
    printf("\nDebit Card Details");
    printf("\n-----------------------------------------------------");
    printf("\n Fields with (*) are compulsory");
    printf("\nCard Number*: ");
	scanf("%d", &card_num);
    printf("\n Card Expiry on,");
    printf("\nMM* \t ");
	scanf("%d", &mm);
    printf("\nYY* \t ");
	scanf("%d", &mm);
    printf("\n\nEnter CVV*: ");
	scanf("%d", &cvv);
    printf("\n-----------------------------------------------------");
	printf("\nPress 'Enter' to continue with Payment");
	do{
		if(getch()==13){ //allows only input of enter
            system("cls");
            otp_screen();
        }
        else{
            continue;
        }
    }while(getch()!=13);
}
void otp_screen(){
	char otp[10];
	system("cls");
	printf("\n\n  Enter OTP: ");
	scanf("%s", otp);
	printf("\nPress 'Enter' to continue");
	do{
		if(getch()==13){ //allows only input of enter
            system("cls");
			printf("\n\n\t\t Order Placed Successfully!");
			printf("\n\n\t\t Please wait for 10 seconds");
			printf("\n\t\t LOADING MENU....");
			sleep(9000);
			ecommerce();
        }
        else{
            continue;
        }
    }while(getch()!=13);
}
void align_spaces(char *ptr){
    int size=strlen(ptr);
    int max_size=30;
    int spaces= max_size-size;
    int r;
    for(r=0;r<spaces;r++){
        printf(" ");
    }
}
void Timestamp(){
    char chr, str[110];
    FILE *fp16=fopen("Details.txt" , "r");
    int i;
    for(i=0; i<8; i++){ 		 
        fscanf(fp16, "%s",str);
        if(i==7){
            chr= getc(fp16);
            while(chr != EOF){
                chr=getc(fp16);//to get next char from file
                printf("%c", chr);
            }
            fclose(fp16);
            break;
        }
		else{
			continue;
		}
    }
	
}
void exit_screen(){
	system("cls");
	printf("\n\n\tProgrammers,");
	printf("\n\t1. Justin T Joseph");
	printf("\n\t2. Chepuri Vyshnavi Lakshmi Sravya");
	printf("\n\t3. Chanikya Manoj Ginjupalli");
	printf("\n\nClosing Application....");
	sleep(5000);
	system("cls");
	printf("\n\n\n\tTHANK YOU!!\n\n");
	exit(0);
}

int ch,age,value;
char Fname[20], Lname[20],password[10],u_name[20], u_mail[20] ;
float mtr, kg;
int main()
{	
	system("cls");
	printf("---------------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\t\t\tWELCOME!\n\t\t\t\t\tDesktop Healthcare Assistant\t\t\t\t\t\t\n");
	printf("---------------------------------------------------------------------------------------------------\n");
    
    printf("1.Register\n2.Login\nEnter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: Register();
                break;
        case 2:	Login();
                break;
        default:printf("!!!INVALID CHOICE!!!\n\n");
                sleep(10);
                break;
    }
		return 0;     
}

int main_screen(){
    system("cls");
    printf("***************************************************************\n");
	printf("\t\t\t\tMAIN MENU\t\t\t\t\t\t\n");
	printf("***************************************************************\n");
    printf("1.E-commerce\n2.Workout Planner\n3.Remidies\n4.Account info\n5.Exit\nEnter Your Choice: "); 
	scanf("%d",&value);
	switch(value)
		{
		    case 1: ecommerce();
				    break;
			case 2: workoutPlanner();
					break;
			case 3: remedies();
					break;
			case 4: accountinfo();
					break;
			case 5: exit_screen();
					break;
			default:exit(0);
					break;
		}
    return 0;
}


void remedies(){
	system("cls");
	int ch;
	printf("\nWhat problem are u facing? ");
	printf("\n------------------------------------------------------------------");
	printf("\nID\tProblem Name");
	printf("\n------------------------------------------------------------------");
	printf("\n1.\tHeadache\n2.\tAbdominal Pain\n3.\tDizziness\n4.\tFatigue");
	printf("\n----------------------------------------- ------------------------");
	printf("\nEnter ID Here(Enter 0 if your problem name isnt present): ");
	scanf("%d", &ch);

	if(ch==0){
		system("cls");
		printf("Enter Problem Name(in single word): ");
		char pblm[100];
		FILE *fp15=fopen("ProblemsToBeAdded.txt","a");
		scanf("%s", pblm);
		fprintf(fp15, "%s", pblm);
		fprintf(fp15,"\n");
		fclose(fp15);
		printf("\nWe will try to tell about this, in our next Update.");
		printf("\nThankyou!");
		sleep(3000);
		main_screen();
	}
	else{
		Loader();
		system("cls");
		char fname[25];
		FILE *fp7;
		sprintf(fname,"REMEDIES\\%d.txt",ch); //sprintf stands for “String print”. Instead of printing on console, it store output on char buffer which are specified in sprintf
		fp7=fopen(fname,"r");
		if(fp7!= NULL){
			char chr;
			chr= getc(fp7);// characters of the file are stored in chr
			printf("%c", chr);
			while(chr != EOF){
				chr=getc(fp7);//to get next char from file
				printf("%c", chr);
			}
			fclose(fp7);
		}
		printf("\n\nPress 'Enter' to go back to Main Menu");
		do{
		if(getch()==13){ //allows only input of enter
            system("cls");
            main_screen();
        }
        else{
            continue;
        }
        }while(getch()!=13);
	}
}


void View_cart(){
    checkout();
}

void Register(){
    FILE *fp = NULL;
    fp=fopen("Details.txt","w");
    printf("\nRegister account\nEnter First Name:");
	scanf("%s",Fname);
	printf("Enter Last Name:");
	scanf("%s",Lname);
	printf("Create a username:");
	scanf("%s",u_mail);
	printf("Enter Height(in metres):");
	scanf("%f",&mtr);
	printf("Enter Weight(in Kg):");
    scanf("%f",&kg);
	printf("Enter Age:");
	scanf("%d",&age);
	printf("Enter Password:");
    scanf("%s",password);
	fprintf(fp,"%s",Fname);
    fprintf(fp, "\n");
	fprintf(fp,"%s",Lname);
    fprintf(fp, "\n");
	fprintf(fp,"%s",u_mail);
    fprintf(fp, "\n");
    fprintf(fp,"%f",mtr);
    fprintf(fp, "\n");
	fprintf(fp,"%f",kg);
    fprintf(fp, "\n");
    fprintf(fp,"%d",age);
    fprintf(fp, "\n");
	fprintf(fp,"%s",password);
    fprintf(fp, " \n");
    time_t t;   // not a primitive datatype
    time(&t);
    fprintf(fp,"%s",ctime(&t));  //  date of account creation
    fprintf(fp,"\n"); 
	fclose(fp);
    main_screen();
}
int Login(){
	char name_pass[110]="";
	char name_pass_entered[110];
	printf("Enter login details\nEnter Username:");
	scanf("%s",u_name);
	strcpy(name_pass_entered,u_name);
	printf("Enter password:");
	scanf("%s",password);
	strcat(name_pass_entered,password);

	char str[70];
	FILE *f = fopen("Details.txt" , "r"); 
	if(f == NULL){
			printf("\nYou haven't created account");
            printf("\nPls create account!");
            sleep(5000);

			return main(); 
	}
	else{
		int i;
		for(i=0;i<8; i++){
			fscanf(f, "%s",str);
			
			if(i==2 || i ==6){
				strcat(name_pass, str);
			}
		}
	}
	//now program will check whether input credenials match with that in file or not
	if(strcmp(name_pass,name_pass_entered)==0){
		printf("\n Login Succesful!! \n");
        sleep(1000);
        

	}
	else{
		printf("\n Login failed! \n");
		sleep(1000);
		Loader();
		return main();
	}
	
	fclose(f); // close file
    main_screen();
}

void accountinfo(){
	system("cls");
	Loader();
	system("cls");
	char str[110],timestamp[110];
	char s_age[5], s_mtr[50], s_kg[50]; 
	float MTR,KG;
    FILE *f = fopen("Details.txt" , "r");
    for(int i =0; i<9; i++){ 		 
        fscanf(f, "%s",str);
		if(i==0){
			strcpy(Fname,str);
		}
		else if(i ==1){
			strcpy(Lname,str); 
		}
		else if(i ==2){
			strcpy(u_name,str); 
		}
		else if(i ==3){
			strcpy(s_mtr,str);
			MTR=atof(s_mtr);
		}
		else if(i ==4){
			strcpy(s_kg,str);
			KG=atof(s_kg); 
		}
		else if(i ==5){
			strcpy(s_age,str); 
		}
		else{
			continue;
		}
    }
	
	float bmi = Calculate_BMI(&KG,&MTR);
	char wt_status[50];
	if(bmi<18.5){
		strcpy(wt_status,"Underweight");
	}
	else if(bmi>=18.5 && bmi<25){
		strcpy(wt_status,"Normal Weight");
	}
	else if(bmi>=25 && bmi<30){
		strcpy(wt_status,"Overweight");
	}
	else{
		strcpy(wt_status,"Obesity");
	}


	fclose(f);
	printf("***************************************************\n");
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Account Info \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n***************************************************\n");
    printf("\tDate of Account Creation: ");
    Timestamp();
	printf("\n             Name: %s ", Fname);
	printf("%s \n", Lname);
	printf("         Username: %s \n", u_name);
	printf("           Height: %s metre \n", s_mtr);
	printf("           Weight: %s kg \n", s_kg);
	printf("              Age: %s \n", s_age);
	printf("           B.M.I.: %.2f \n", bmi);
	printf("    Weight Status: %s \n",wt_status);
    printf("\n\nPress 'Enter' to go back to Main Screen");
    returnfunc();
    
}

void ecommerce(){
	system("cls");
	printf("---------------------------------------------------------------------");
	printf("\n\t\tWelcome to Online Store\n");
	printf("---------------------------------------------------------------------");
	printf("\n1.View Items\n2.View Cart\n3.Back to Main Screen");
    printf("\nEnter your choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: View_items();
                break;
		case 2:	View_cart();
				break;
		case 3: printf("\nTHANK YOU!");
				sleep(1000);
				Loader();
				main_screen();
                break;
		default:printf("\n!!!INVALID CHOICE!!!\n\n");
                sleep(1000);
                ecommerce();
			    break;
	}
}

int View_items(){
	system("cls");
	int item_id[10];
	FILE *fp =fopen("ItemsName.txt","r");
    char chr;
    chr= getc(fp);// characters of the file are stored in chr
    printf("%c", chr);
    while(chr != EOF){
        chr=getc(fp);//to get next char from file
        printf("%c", chr);
    }
    fclose(fp);
	printf("\n\nEnter an Item ID to ADD to Cart: ");
	scanf("%s", item_id);

	FILE *fp2;
	fp2=fopen("CartItems.txt","a");
	fprintf(fp2,"%s\n", item_id );

	fclose(fp2);

	printf("\n1.Checkout\n2.Add another item to Cart");
	printf("\nEnter your choice: ");
	scanf("%d",&ch);

	
    if(ch==1){
        system("cls");
        return checkout();
    }
    else if(ch==2){
        return View_items();
    }
    else{
        remove("CartItems.txt");
        printf("\nInvalid Input!!");
        printf("\nGoing Back to Main-Screen...");
        sleep(2000);
        return main_screen();
    }
}

int checkout(){
	FILE *fp3;
	fp3=fopen("CartItems.txt","r");
	if(fp3==NULL){
		printf("\nYou have added nothing to cart!");
		printf("\nGoing Back to main screen, Pls Wait!!");
		sleep(4000);
		return main_screen();
	}
	int num_lines= lines_in_file(fp3);
	fclose(fp3);

	char strin[5];
	int id_arr[num_lines];

	FILE *fp2;
	fp2=fopen("CartItems.txt","r");
	int i;
	for(i=0;i<num_lines; i++){
		fscanf(fp2, "%s",strin);
		id_arr[i]=atoi(strin);
	}
    fclose(fp2);
	remove("CartItems.txt");
	int p;
	
    //----------------------creating structure objects--------------------------
    char str[50];
    FILE *fp4;
    fp4=fopen("ItemsName.txt", "r");
    int num_lines2 =lines_in_file(fp4);
    fclose(fp4);
    struct item obj[(num_lines2)];
    //now we are initialising variables of obj[0] with random numbers(or strings), because then, for all other items the index of the obj array and the item_id will be same
    obj[0].id=0;
    strcpy(obj[0].item_name,"garbage");
    obj[0].price=0.0;

    FILE *fp5;
    fp5=fopen("ItemsName.txt", "r");
    int upperLimit= 3*num_lines2;
    int j, counter=0,flag=0,index=1;
    for(j=0; j<upperLimit;j++){
        //the if condition allows us to skip prining the column header
        if(counter<=2){ 
            fscanf(fp5, "%s",str);
            counter+=1;
        }
        else{
            fscanf(fp5, "%s",str);
            if(flag==0){
                obj[index].id=atoi(str);
                flag=1;
            }
            else if(flag==1){
                strcpy(obj[index].item_name,str);
                flag=2;
            }
            else if(flag ==2){
                obj[index].price=atof(str);
                flag=0;
                index +=1;
            }
            else{
                continue;
            }
        }
    }
    fclose(fp5);
    //----------------completed struct obj declaration-----------------------------------------


    printf("\n-----------------------------------------------------------------------");
    printf("\n   Item_id \t\t Item_Name \t\t\tPrice(RS.)");
    printf("\n-----------------------------------------------------------------------");
	

    int m;
    float net_amount=0;
    float delivery_charge=80.0;
    for(m=0;m<num_lines-1;m++){
        printf("\n     %d",obj[id_arr[m]].id); 				//prints object id
        printf(" \t\t\t %s", obj[id_arr[m]].item_name);  	// prints object name
		align_spaces(obj[id_arr[m]].item_name);
        printf("%.2f", obj[id_arr[m]].price);				//prints object price
		net_amount+=obj[id_arr[m]].price;
    }
    net_amount+=delivery_charge;
    printf("\n-----------------------------------------------------------------------");
    printf("\n  Delivery Charges");
    spaces(36);
    printf("Rs.%.2f", delivery_charge);
    printf("\n-----------------------------------------------------------------------");
    printf("\n   Net Amount");
    spaces(40);
    printf("Rs.%.2f",net_amount);
    printf("\n-----------------------------------------------------------------------");
    printf("\nPress Enter to continue with payment: ");
    
    do{
        if(getch()==13){ //allows only input of enter
            return payment();
        }
    }while(getch()!=13);
  
    
}
int workoutPlanner(){
	system("cls");
    int ch;
    int dt;
    FILE *fp8 = fopen("LevelDate.txt", "r");
    if(fp8== NULL){
        FILE *fp10;
        fp10=fopen("DaysCompleted.txt","w");
        printf("How many pushups are u able to do?");
        printf("\n1.Less than 15 pushups(Beginner Level)");
        printf("\n2.More than 15 pushups(Intermediate Level)");
        printf("\n-------------------------------------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
        if(ch==1){
            dt= date_today();
            FILE *fp9;
            fp9=fopen("LevelDate.txt", "w");
            fprintf(fp9,"%s", "Beginner");
            fprintf(fp9, "\n");
            fprintf(fp9, "%d", dt);
            fclose(fp9);
            fprintf(fp10,"%d",1);
            fprintf(fp10, "\n");
            fprintf(fp10,"%d",dt);  //last_modified_date
            fclose(fp10);
            printf("\n\nSetting up Beginner Level plan");
			printf("\nPlease wait!");
			sleep(5000);
			system("cls");
            int k=1;
            printf("\n-------------------------------------------------");
            printf("\nDays Completed: 1 of 28");
		    printf("\n-------------------------------------------------");
            display_planner(&k, "Beginner");

        }
        else if(ch==2){
            dt= date_today();
            FILE *fp9;
            fp9=fopen("LevelDate.txt", "w");
            fprintf(fp9,"%s", "Intermediate");
            fprintf(fp9, "\n");
            fprintf(fp9, "%d", dt);
            fclose(fp9);
            fprintf(fp10,"%d",1);
            fprintf(fp10, "\n");
            fprintf(fp10,"%d",dt);  //last_modified_date 
            fclose(fp10);
            printf("\n\nSetting up Intermediate Level plan");
			sleep(2000);
			Loader();
			system("cls");
            int k=1;
            printf("\n-------------------------------------------------");
            printf("\nDays Completed: 1 of 28");
		    printf("\n-------------------------------------------------");
            display_planner(&k, "Intermediate");
        }
        else{
            printf("Invalid choice!!");
            return workoutPlanner();
        }
    }
    else{
        char str1[10], str2[10], level[20];
        int days, last_modified_dt;
        fscanf(fp8,"%s",str1);
        strcpy(level, str1);
        fscanf(fp8,"%s",str2);
        int dt_created= atoi(str2);
        fclose(fp8);
        
        int today=date_today();

        
        FILE *fp11 = fopen("DaysCompleted.txt","r");
        fscanf(fp11,"%d",&days);
        fscanf(fp11, "%d", &last_modified_dt);
        fclose(fp11);
    

        if(today!= last_modified_dt){ //this means date of creation of planner and today's date are different
            days+=1;
            FILE *fp12 = fopen("DaysCompleted.txt","w");
            fprintf(fp12,"%d",days);
            fprintf(fp12, "\n");
            fprintf(fp12,"%d",today);
            fclose(fp12);
        }
        FILE *fp13 = fopen("DaysCompleted.txt","r");
        fscanf(fp13,"%d",&days);
        fclose(fp13);
		system("cls");
		printf("\n-------------------------------------------------");
        printf("\nDays Completed: %d of 28", days);
		printf("\n-------------------------------------------------");
        display_planner(&days, level);
    }
    return 0;

}
int display_planner(int *dts, char *lvl){
    int n,l,t; 
    if(strcmp(lvl,"Beginner")==0){ //Beginner Level
        l=1;
    }   
    else{      //Intermediate level 
        l=3; 
    }

    //week1
    if(*dts<=7){   
        n=5,t=30;
        printf("\n\tJumping Jacks     %d seconds", t);
        printf("\n\tArm Scissors 	  %d seconds", t);
        printf("\n\tRhomboid Pulls   x%d times", n+4);
        printf("\n\tWide Arm Pushups x%d times", n+l);
        printf("\n\tIncline pushup 	 x%d times", n+4);
        printf("\n\tArm Raises		 x%d times", n+4);
        printf("\n\tInchworms		 x%d times", n+3);
        printf("\n\tPushups			 x%d times", n+l);
        printf("\n\tArm Raises		 x%d times", n+4);
        printf("\n\tSit-ups			 x%d times", n+l);
        printf("\n\tPlank			  %d seconds", t+l);
        printf("\n\tReclined Rhomboid Squeezes x%d times", n+4);
        printf("\n\tChild's Pose	  %d seconds", t);
    }  
    //week2
    else if(*dts>7 && *dts<=14 ){   
        n=8,t=33;
        printf("\n\tJumping Jack		 %d seconds", t);
        printf("\n\tMountain Climber	 x%d times", n+l+3);
        printf("\n\tPlank				 %d seconds", t+5);
        printf("\n\tRussian Twist		 x%d times", n+l+2);
        printf("\n\tPushups				 x%d times", n+l+4);
        printf("\n\tHeel Touch			 x%d times", n+l);
        printf("\n\tWide Arm Pushups	 x%d times", n+l+5);
        printf("\n\tStaggered Pushups	 x%d times", n+l);
        printf("\n\tPushups				 x%d times", n+l);
        printf("\n\tPushup & Rotation	 x%d times", n+l+1);
        printf("\n\tStaggered Pushups	 x%d times", n+l);
        printf("\n\tWide Arm Pushups	 x%d times", n+l);
        printf("\n\tDecline Pushups		 x%d times", n);
        printf("\n\tPushups				 x%d times", n);
        printf("\n\tShoulder stretch	 %d seconds", t);
        printf("\n\tSide Bridges Left	 x%d times", n+l);
        printf("\n\tSide Bridges Right	 x%d times", n+l);
        printf("\n\tCobra stretch		 %d seconds", t);
        printf("\n\tChest stretch		 %d seconds", t);       
    }  
    //week3
    else if(*dts>14 && *dts<=21 ){   
        n=14,t=35;
        printf("\n\tJumping Jack		 %d seconds", t);
        printf("\n\tMountain Climber	 x%d times", n+l);
        printf("\n\tRussian Twist		 x%d times", n);
        printf("\n\tSit-ups				 x%d times", n);
        printf("\n\tAbdominal Crunches	 x%d times", n+2);
        printf("\n\tLeg Raises			 %d times", n-2);
        printf("\n\tPlank				 %d seconds", t);
        printf("\n\tV-UP				 x%d times", n+l);
        printf("\n\tPushups				 x%d times", n+l-2);
        printf("\n\tHeel Touch			 x%d times", n+4);
        printf("\n\tDiamond Pushups		 x%d times", n+l);
        printf("\n\tSpiderman Pushups	 x%d times", n+l);
        printf("\n\tDecline Pushups		 x%d times", n+l);
        printf("\n\tPlank				 %d seconds", t+10);
        printf("\n\tPushups				 x%d times", n);
        printf("\n\tWide Arm Pushups	 x%d times", n-2);
        printf("\n\tDecline Pushups		 x%d times", n-6);
        printf("\n\tShoulder stretch	 %d seconds", t);
        printf("\n\tCobra stretch		 %d seconds", t);
        printf("\n\tChest stretch		 %d seconds", t);
    }  
    //week4
    else if(*dts>21 && *dts<=28 ){   
        n=16,t=37;
        printf("\n\tJumping Jack		 %d seconds", t);
        printf("\n\tAbdominal Crunches	 x%d times", n+2);
        printf("\n\tSit-ups				 x%d times", n+l);
        printf("\n\tRussian Twist		 x%d times", n+6);
        printf("\n\tMountain CLimber	 x%d times", n-4);
        printf("\n\tCrossover Crunches	 x%d times", n+2);
        printf("\n\tBicycle Crunches	 x%d times", n+l);
        printf("\n\tPushups				 x%d times", n+l);
        printf("\n\tV-UP				 x%d times", n+l);
        printf("\n\tInchworms			 x%d times", n-6);        
        printf("\n\tLeg Raises			 x%d times", n-2);
        printf("\n\tKnee Plank			 %d seconds", t-4);
        printf("\n\tStaggered Pushups	 x%d times", n+l);
        printf("\n\tWide Arm Pushups	 x%d times", n+4);
        printf("\n\tDecline Pushups		 x%d times", n+l);
        printf("\n\tPushups				 x%d times", n);
        printf("\n\tShoulder stretch	 %d seconds", t);
        printf("\n\tLeg Raises			 x%d times", n+4);
        printf("\n\tPlank				 %d seconds", t+10);
        printf("\n\tCobra stretch		 %d seconds", t);
        printf("\n\tSpine Lumbar Twist Stretch Left %d seconds", t);
        printf("\n\tSpine Lumbar Twist Stretch Right %d seconds", t);    }  
    //4 weeks completed
    else{
        printf("\nCongrats you have completed your 4-weeks Home workout");
        remove("DaysCompleted.txt");
        remove("LevelDate.txt");
    }
	printf("\n-------------------------------------------------");
	printf("\nPress Enter to go Back to Main Screen: ");
	// returnfunc();
	do{
		if(getch()==13){ //allows only input of enter
            return main_screen();
        }
    }while(getch()!=13);
}
