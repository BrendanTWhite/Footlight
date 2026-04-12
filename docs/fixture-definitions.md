# Questions to be answered

## Where to have Fixture Definitions?

- In tables in the Show database file?
  - Yes - need it in the main file
- Maybe have it in a JSON in some library in the user's machine, as well?
  - I mean, we could do ... but let's not?
  - User can store thier files wherever they want, but software will just use what's in the show database file.
  - Otherwise we need to

## Where to get Fixture Definitions?

- On a Footlight / Haydone Flynn website (that I need to maintain)? No.
- Just use [Open Fixture Libary](https://open-fixture-library.org)? Probs yes.
- Can aso build your own (see [GDTF Share](https://gdtf-share.com)).

## What format to use?

- Just use GDTF?
  - probs yeah - nice and simple.
  - Lots of [online doco](https://github.com/mvrdevelopment/).
    - This includes an API to get GDTFs down from their library
    - Also includes a GDTF reader library in C++
    - And a GDTF XSD Schema
- Make my own, based on [the OFL JSON](https://github.com/OpenLightingProject/open-fixture-library/blob/master/docs/fixture-format.md)?
  - this is Plan B, if I can't (or don't wan to) use plain vanilla GDTF.
