# Exercise 1.1 - Bringcorp Rewards

*Note: This is a satirical and fictional exercise, not based in reality.*

In the latest meeting at Bringcorp of the Content Ethics Board, it was determined that Bringle viewers should be able to receive bonuses for being a loyal Bringle viewer and donator. They decided they want to make an app where viewers can submit their information, and then the app can tell them what benefits they are eligible for.

They decided on a multi-stage system for determining a score based off the individual user, and then that score will decide what perks the viewer gets.

Your task is to code this application in C, based on this template!

## Part 1: Storing data
To start, we need to track the user's current score and their username globally. The template already contains the variable declarations, but you need to set the correct initial values and modifiers.
1. We need an integer variable `score` that tracks the user's current score. This score should initially be `0`, and should not be able to become negative.
2. We need a global string variable `username` that holds the username. The maximum length of a username is 255 characters. Make sure to allocate enough memory!

## Part 2: Asking the user for details
In the template you can already find functions for each step, as well as calls to each function in `main`.

At the start, the program will greet the user. This part is already implemented. Then we begin asking for information:
### 2.1 Username
First, we want to get the username.
1. Print this message using `printf`: `Please enter your username (max 255 characters):\n`.
2. Use `scanf` to read the user's username. Make sure the user cannot enter a username longer than 255 characters! *(Reminder: Use `%<length>d` for the formatter, with `<length>` being the maximum length that should be read.)*
3. Bringle has determined that having a longer username means being a better person. So we want to add 1 point per character in the username to our total score.

*Hint: You need to include the `<string.h>` library and use a function from it to determine the point count.*
### 2.2 Birthday
Another important factor is the user's birthday.
1. Print this message using `printf`: `Please enter your birthday (YYYY/MM/DD):\n`
2. Use `scanf` to read the user's birthday. *(Tip: You may want to use multiple different fields seperated by `/`).*
3. After months of research, Bringcorp has identified this to be the perfect scientifically accurate formula for calculating the points. Use it to determine the points added to the score:
```
<days> * sin(<days> / <months>) + (<years> / 2)
```
*Note: The `sin()` function is defined in `<math.h>`, you need to include it. Do not round.*
### 2.3 Donation money
Due to budget cuts at Bringcorp, another important topic to them is the total money that user donated.
1. Print this message using `printf`: `Please enter the total money you donated to Bringle in USD:\n`
2. Use `scanf` to read the user's answer. It should be a `float` so that the user can input the amount of cents as well.
3. Even though Bringcorp likes money, they don't want to seem desperate and make this system pay-to-win. Therefore, the maximum amount of points that can be gained in this step is 100. Otherwise, US$1 = 1 point.

*Note: Round the points using `round` from `<math.h>`.*
### 2.4 Membership
Members are Bringle's most loyal viewers, and thus it was decided they should get a boost.
1. Print this message using `printf`: `Are you a Bringle Crisp (C) or Bringle Stack (S) member or neither (N)?\n`
2. Users should now input one character that's either `C`, `S` or `N`. If they input any other character, it should be treated as `N`. Use `scanf` to get what character the user entered. *(Note: Due to a quirk with `scanf`, you have to use the sequence " %c" with a whitespace.)*
3. Afterwards, if they are a member, ask: `How many months have you been a member?\n`. Capture the amount of months using `scanf`.
4. Bringle Crisp members should receive 500 extra points for every month they've been a member for, while Bringle Stack members should receive 1000 for every month.
## Part 3: Results
After all of this data has been entered by the user and the score has been calculated, print the following string with `printf`: `<username>, you have <score> points.\n` where `<username>` should be the username you stored and `<score>` should be the score number you calculated.

Afterwards the user should get informed about the perks they can receive in `main` or your own function that gets called by `main`.

Bringcorp has not decided on what those perks should be, so you can freely decide what they should be and at what point ranges the user gets them!

**Make sure to send me your final C code, I'd love to see what you came up with!**