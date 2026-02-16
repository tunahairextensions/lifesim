  #include <iostream>
  #include <cstdlib>
  #include <ctime>
  #include <string>
  using namespace std;

  // ---Global Variables---
  // Booleans
  bool married = false;
  bool employed = false;
  bool adultGg = false;

  // Chars
  char choice;

  // Ints
  int iqIndex;
  int wealthIndex;
  int traitIndex;
  int appearanceIndex;
  int countryIndex;

  // ---Void Functions---
  void school();
  void noSchool();
  void employment();
  void adulthood();
  void furtherAdulthood();
  void criminal();
  void furtherCriminal();
  void criminalEnding();
  void elderly();

  int main () 
  {
  srand(time(0));

  cout << R"(
        _---~~(~~-_.
      _{        )   )
    ,   ) -~~- ( ,-' )_
  (  `-,_..`., )-- '_,)
  ( ` _)  (  -~( -_ `,  }
  (_-  _  ~_-~~~~`,  ,' )
    `~ -^(    __;-,((()))
          ~~~~ {_ -_(())
                `\  }
                  { }    
  )" << endl;

  // Menu Screen
  cout << "Welcome to LIFE SIMULATOR" << endl;
  cout << "Press any button to continue." << endl;
  cin >> choice;

  // Luck
  cout << " " << endl;
  cout << "You have been born." << endl;

  // Country RNG
  string countries[24] = {"USA", "Japan", "Germany", "China", "India", "Brazil", "Mexico", "Indonesia", "Turkey", "South Africa", "Vietnam", "Thailand", "Egypt", "Argentina", "Phillipines", "Nigeria", "Colombia", "Malaysia", "Pakistan", "Ukraine", "Peru", "Burundi", "South Sudan", "Afghanistan"};
  countryIndex = rand() % 24;
  cout << "You were born in " << countries[countryIndex] << "." << endl;

  // IQ RNG
  string intellect[3] = {"low intelligence", "average intelligence", "high intelligence"};
  iqIndex = rand() % 3;
  cout << "You possess " << intellect[iqIndex] << "." << endl;

  // Appearance RNG
  string appearance[3] = {"ugly looks", "average looks", "attractive looks"};
  appearanceIndex = rand() % 3;
  cout << "You have " << appearance[appearanceIndex] << "." << endl;

  // Wealth RNG
  string wealth[3] = {"poor", "middle class", "rich"};
  wealthIndex = rand() % 3;
  cout << "You are among the " << wealth[wealthIndex] << "." << endl;

  // Personality Traits RNG
  string traits[10] = {"introverted", "extroverted", "neurotic", "optimistic", "controversial", "compassionate", "lazy", "hard-working", "curious", "indifferent"};
  traitIndex = rand() % 10;
  cout << "You tend to be " << traits[traitIndex] << "." << endl;

  // Playthrough
  cout << "Press any button to continue." << endl;  
  cin >> choice;

  cout << " " << endl;
  cout << ">> 6 years..." << endl;
  cout << "You are now ready for education." << endl;
  cout << "Press any button to enroll into a school." << endl;
  cin >> choice;

  if(wealthIndex < 1)
    noSchool();
  else if(wealthIndex >= 1)
    school();

  return 0;
  }


  // Void Engines
  void school()
  {
    cout << " " << endl;
    cout << "You were able to afford schooling." << endl;
    cout << "You are now enrolled into a school." << endl;
    cout << "Press any button to continue." << endl;
    cin >> choice;

    cout << " " << endl;
    cout << ">> 12 years..." << endl;
    if(iqIndex > 1 || traitIndex == 7)
    {
      cout << "You have graduated with impressive grades." << endl;
      adultGg = true;
      employment();
    }
    else if(iqIndex <= 1)
    {
      cout << "You have graduated, albeit with subpar grades." << endl; 
      employment();
    }
  }

  void noSchool()
  {
      cout << " " << endl;
      cout << "You are unable to afford schooling!" << endl;
      cout << "Press any button to continue." << endl;
      cin >> choice;

      bool menuOpen = true;
    while (menuOpen) {
      cout << "What would you like to do from here?" << endl;
      cout << "A. Find a low-paying job" << endl;
      cout << "B. Get married" << endl;
      cout << "C. Dive into the world of crime" << endl;
      cin >> choice;
      if(choice == 'a' || choice == 'A') 
      {
        cout << "You managed to get employed into a low-paying job." << endl;
        employed = true;
        menuOpen = false;
        adulthood();
      }
      else if(choice == 'b' || choice == 'B') 
      {
        if(employed == false)
          cout << "You need to get a job first! Try something else" << endl;
        else
        {
          cout << "You managed to get married." << endl;
          menuOpen = false;
          married = true;
          furtherAdulthood();
        }
      }
      else if(choice == 'c' || choice == 'C')
      {
        cout << "You have decided to gain money illegally." << endl;
        criminal();
      }
    }
  }

  void employment()
  {
    if (adultGg == true)
    {
      cout << " " << endl;
      cout << "Press any button to continue." << endl;
      cin >> choice;
      cout << ">> 5 years..." << endl;
      cout << "You have managed to secure a good job due to your qualifications." << endl;
      adulthood();
    }
    else if (adultGg == false)
    {
      cout << " " << endl;
      cout << "Press any button to continue." << endl;
      cin >> choice;
      cout << ">> 5 years..." << endl;
      cout << "You have managed to secure a mediocre job due to your qualifications" << endl;
      adulthood();
    }
  }

  void adulthood()
  {
    cout << " " << endl;
    cout << "Press any button to continue." << endl;
    cin >> choice;
    cout << "It seems as though its time to get married and start a family." << endl;
    cout << "Press any button to find a wife." << endl;
    cin >> choice;

    if (wealthIndex > 1)
    {
      cout << "You have managed to get married!" << endl;
      married = true;
      furtherAdulthood();
    }
    if (appearanceIndex < 1)
    {
      cout << "Unfortunately, you are too ugly to get a wife!" << endl;
      furtherAdulthood();
    }
    else if (appearanceIndex >= 1)
    {
      cout << "You have managed to get married!" << endl;
      married = true;
      furtherAdulthood();
    }
  }

  void furtherAdulthood()
  {
    cout << " " << endl;
    cout << "Press any button to continue" << endl;
    cin >> choice;
    cout << ">> 5 years..." << endl;
    if (married == true)
    {
      cout << "You have grown a family with your wife." << endl;
      elderly();
    }
    else if (married == false)
    {
      cout << "The lonely monotonous nature of your routine is withering you down." << endl;
      cout << "What would you like to do from here?" << endl;
      cout << "A. Get a hobby" << endl;
      cout << "B. Focus on your career" << endl;
      cin >> choice;
      if(choice == 'a' || choice == 'A')
        {
          cout << "You get a hobby to fill up your lonely hours." << endl;
          elderly();
        }
      else if (choice == 'B' || choice == 'b')
        {
          cout << "You decide to focus on your career to give yourself a feeling of purpose and ambition." << endl;
          elderly();
        }
    }
  }

  void criminal()
  {
    cout << " " << endl;
    cout << "Press any button to continue" << endl;
    cin >> choice;
    cout << "Pick your crime of choice:" << endl;
    cout << "A. Drug trafficking" << endl;
    cout << "B. Theft" << endl;
    cout << "C. Counterfeiting" << endl;
    cin >> choice;
    switch(choice)
    {
      case 'a':
      case 'A':
        cout << "You have decided to obtain and sell drugs." << endl;
        furtherCriminal();
        break;
      case 'b':
      case 'B':
        cout << "You have decided to steal and rob." << endl;
        furtherCriminal();
        break;
      case 'c':
      case 'C':
        cout << "You have decided to produce conterfeit products." << endl;
        furtherCriminal();
        break;
    }
  }

  void furtherCriminal()
  {
    cout << " " << endl;
    cout << "Press any button to continue and begin making money." << endl;
    cin >> choice;

    bool caught = false;

    while (caught == false)
    {
      int chanceOfSuccess = 70;
      int roll = (rand() % 100) + 1;

      if (roll <= 70)
      {
        cout << "You have made a profit." << endl;
        cout << "Press any button to try again." << endl;
        cin >> choice;
      }
      else if (roll > 70)
      {
        cout << "You have been caught!" << endl;
        caught = true;
        criminalEnding();
        return;
      }
  }
  }

  void criminalEnding()
  {
    cout << " " << endl;
    cout << "Press any button to continue." << endl;
    cin >> choice;
    cout << "You have been caught by the authorities, and all your assets have been seized." << endl;
    cout << "You are facing many years in prison. Easy come, easy go." << endl;
    cout << "GAME OVER." << endl;
    exit(0);
  }

  void elderly()
  {
    cout << " " << endl;
    cout << ">> 30 years..." << endl;
    cout << "Press any button to continue." << endl;
    cin >> choice;
    cout << "You are growing old, and your body is withering." << endl;
    cout << "You don't feel like you do before." << endl;
    if(married)
      {
      cout << "Perhaps your children will keep you accompanied." << endl;
      exit(0);
      }
    else
      {
      cout << "Perhaps you will live the rest of your days in acceptance." << endl;
      exit(0);
      }
  } 