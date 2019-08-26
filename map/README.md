# MAPS

### Definition

Maps are used to generate the spacial localization of players during a match.



### Symbols

```###```  &rarr; Represents a null location, where is unaccessible to players.

```[ ]``` &rarr; Represents a block room, where the exits exists on every adjacent accessible spot.

```| |``` &rarr; Represents a vertical corridor, where the exits exists only on top and bottom, if that locations have a accessible spot.

```===``` &rarr; Represents a horizontal corridor, where the exits exists only on left and right, if that locations have a accessible spot.

### Format

```
SymSymSymSym\n
SymSymSymSym\n
SymSymSymSym\n
```

Every map should contain this preset, where:

- *Sym* represents any Symbol
- Shouldn't have white spaces out of symbols
- Need to have a rectangular form
- Every line should be ended with *\n*