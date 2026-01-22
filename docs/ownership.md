# Ownership Diagram

Object Ownership Diagram for main Footlight structures

```mermaid
erDiagram
    direction LR

App ||--|| HomeWindow : has

App ||--o{ ShowWindow : has

ShowWindow ||--|| Show :has

Show {
    int id
    string name
    File fileOnDisk
    bool dirty
}

Show ||--o{ Universe : contains
Universe {
    string name
    obj connection
}

Show ||--o{ FixtureType : contains
FixtureType {
    string name
    array channels
}

Show ||--o{ Fixture : contains
Fixture {
    string name
    string bar
    int dmxAddress
    ptr fixtureType
    ptr universe
}

Show ||--o{ FixtureGroup : contains
FixtureGroup {
    string name
}
FixtureGroup ||--o{ GroupItem : contains
GroupItem {
    int sequence
    ptr fixture
}

Show ||--o{ State : contains
State {
    string code
    string name
}
State ||--o{ StateItem : "contains"
StateItem {
    enum stateItemType
    ptr fixture
    ptr group
    ptr state
    array channelValues
}

Show ||--o{ Cue : contains
Cue {
    int seq
    double id
    State state
    string cueText
    int delay
    int fade
}

```
