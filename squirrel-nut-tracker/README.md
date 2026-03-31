# The Squirrel Nut Tracker

## Scenario
Researchers are studying the behavior of squirrels in a forest where they compete to hide and collect nuts. You are tasked with implementing a tracker that simulates this behavior. Your system must manage hiding locations, track individual nuts by weight and expiration, and simulate complex retrieval logic based on squirrel preferences and physics.

## General Rules And Data Types
- Timestamps are represented as floats (seconds since the Unix Epoch, valid to millisecond precision). They are guaranteed to be globally ever-increasing.
- Weights are represented as floats in grams (valid to milligram precision).
- If any constraint is violated during an operation or an invalid location is provided, the operation must silently fail (for example, return `False` or an empty list).
- Total instructions: `1 < N < 2^15`.

## Class Definition: `SquirrelResearch`

### Constructor

```python
def __init__(self, locations: dict[str, int])
```

- Initializes the tracker with all available hiding locations.
- `locations` maps a `location_id` string to the total number of levels in that location.
- Locations are shaped like a cone. Levels are filled from the deepest level upwards.
- The capacity of each level follows the Fibonacci sequence starting from the 3rd digit: `1, 2, 3, 5, 8, ...`.
- Example: A location with 3 levels can fit 6 nuts total: 1 at the deepest level, 2 at the middle level, and 3 at the top level.
- Constraints:
  - `1 <= levels < 2^5`
  - `1 <= Q < 2^20`

### Hide Nut

```python
def HideNut(
    self,
    timestamp: float,
    location_id: str,
    nut_id: str,
    nut_weight: float,
    time_to_expire: float,
) -> bool
```

- Attempts to hide a nut.
- Returns `True` if successful, otherwise `False`.
- Nuts must be placed in the lowest available level.
- A level must be completely filled before filling the next level above it.
- A nut is expired immediately after `timestamp + time_to_expire`.
- Fails if:
  - `location_id` is invalid
  - the location is full
  - `nut_id` is already hidden anywhere in the forest
- Constraint: `0 < nut_weight < 20`

### Retrieve Nuts

```python
def RetrieveNuts(
    self,
    timestamp: float,
    location_id: str,
    max_squirrel_capacity_in_nuts: int,
) -> list[str]
```

- Attempts to retrieve nuts from a location.
- Returns the retrieved `nut_id` values in exact pickup order.
- Returns an empty list on failure.
- Retrieval stops when the squirrel reaches `max_squirrel_capacity_in_nuts` or the location becomes empty.

#### Retrieval Rules
1. Start from the upmost level that currently contains nuts.
2. Within a level, retrieve heavier nuts first.
3. If weights are equal, retrieve the alphabetically smaller `nut_id` first.

#### 50% Reach Rule
- If the upmost occupied level is filled to less than 50% of its capacity, the squirrel can also reach the level immediately below it.
- The squirrel prefers the lower level only if its best nut is heavier than the best nut on the upper level.
- If the weights are tied, use the smallest `nut_id` tie-breaker.

#### Falling Rule
- Whenever a nut is removed from a level that is not the upmost occupied level, the lightest nut from the level directly above it falls down to replace it.

#### Expiration Handling
- If a retrieved nut is expired at the given `timestamp`, the squirrel discards it immediately.
- Discarded nuts do not count toward `max_squirrel_capacity_in_nuts`.
- Both retrieved and discarded nuts are permanently removed from the location.

#### ID Reusability
- Once a nut is retrieved or discarded, its `nut_id` becomes available again and may be reused later.

#### Constraint
- `1 <= max_squirrel_capacity_in_nuts < 2^10`
