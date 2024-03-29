# Day-Guessing-Game-
Gauss's formula is a mathematical method for calculating the day of the week for any given date. It is based on the Zeller's Congruence algorithm, which uses a set of modular arithmetic equations to determine the day of the week. Here's how Gauss's formula works:

1. Let `A` be the year minus one (A = year - 1).
2. Calculate `m` as follows:
   - `m` represents the month, with March as 1, April as 2, May as 3, and so on. January and February are treated as months 11 and 12 of the previous year.
   - To calculate `m`, take the month you are interested in, subtract 2, and then take the result modulo 12.
   - For example, if the given month is January (1), you subtract 2 to get -1, and taking modulo 12 results in 11, which corresponds to December of the previous year.
3. Determine the day of the week using the following formula:
   - `h = (q + (13 * (m + 1)) / 5 + K + (K / 4) + (J / 4) - 2 * J) % 7`
     - `h` is the day of the week, where 0 represents Saturday, 1 represents Sunday, 2 represents Monday, and so on.
     - `q` is the day of the month.
     - `m` is the adjusted month value calculated in step 2.
     - `K` is the year of the century (year % 100).
     - `J` is the zero-based century (year / 100).

The value of `h` represents the day of the week, with 0 being Saturday, 1 being Sunday, and so on. This formula calculates the day of the week for a given date based on the day, month, and year values. It is applicable for all dates and provides an accurate result.