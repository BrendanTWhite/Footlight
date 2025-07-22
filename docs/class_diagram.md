# Class Diagram

Class Diagram for main Footlight structures

```mermaid
erDiagram

CueList {
    int id
    string name
}

CueList ||--o{ Cue : contains

Cue {
    int seq
    string cue-text
    int delay
    int fade
}

Cue }o--|| Scene : "is for"

Scene {
    int id
    string name
}

Scene ||--o{ GroupInScene : "contains"

GroupInScene {

}

GroupInScene }o--|| FixtureGroup : ""


FixtureGroup {
    int id
    string name
}

FixtureInGroup }o--|| FixtureGroup : ""

FixtureInGroup {

}

FixtureInGroup }o--|| Fixture : ""


Scene ||--o{ FixtureInScene : "contains"

FixtureInScene {

}

FixtureInScene }o--|| Fixture : ""

FixtureType {
    string name
    array channels
}

Fixture {
    int id
    int dmx-address
    string name
}

Fixture }o--|| FixtureType : "is of type"

Universe {
    string name
    obj connection
}

Fixture }o--|| Universe : "is on"

```
