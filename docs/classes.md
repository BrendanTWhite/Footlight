# Class Diagram

Class Diagram for main Footlight structures

## Aggregation

"has a", eg a show "Has a" state. Hollow diamond on a solid line. Diamond is on containing item's end of the line.

## Association

Links from one to another. Uses a solid line. Can have an open triangle / arrow at one end.

```mermaid
classDiagram

    Show <--o Universe

    Show <--o FixtureDefinition

    Show <--o Fixture
        Fixture <-- FixtureDefinition
        Fixture <-- Universe
    
    Show <--o FixtureGroup
        FixtureGroup <-- Fixture
    
    Show <--o State
        State <-- Fixture
        State <-- FixtureGroup

    Show <--o Cue
         Cue <-- State

```
