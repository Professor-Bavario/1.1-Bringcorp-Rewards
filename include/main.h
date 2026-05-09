extern unsigned int score;
extern char username[];
extern size_t usernameSize;

#ifdef TESTER
extern int test_printf(const char *format, ...);
#define printf test_printf
extern int test_scanf(const char *format, ...);
#define scanf test_scanf
#endif

void calcUsername();
void calcBirthday();
void calcDonations();
void calcMembership();