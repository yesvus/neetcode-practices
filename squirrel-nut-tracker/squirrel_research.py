class SquirrelResearch:
    def __init__(self, locations: dict[str, int]):
        self.locations = locations

    def HideNut(
        self,
        timestamp: float,
        location_id: str,
        nut_id: str,
        nut_weight: float,
        time_to_expire: float,
    ) -> bool:
        raise NotImplementedError

    def RetrieveNuts(
        self,
        timestamp: float,
        location_id: str,
        max_squirrel_capacity_in_nuts: int,
    ) -> list[str]:
        raise NotImplementedError
