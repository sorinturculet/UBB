class event_validator:
    def __init__(self):
        pass
    def validate_mark(self,mark):
        if mark<1 or mark>10:
            raise ValueError("Mark should be between 1 and 10")