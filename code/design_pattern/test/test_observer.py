from src.OOP_patterns.observer_pattern import Notifier, Observer
import unittest
from enum import Enum


class Event(Enum):
    Earthquake = 0
    Joke = 1


class SomeWhere:
    def __init__(self):
        self._member = {}

    def add_member(self, member):
        self._member[member] = "is here"

    def remove_member(self, member):
        del self._member[member]

    # override update protocol
    def update(self, event):
        global res

        if event == Event.Earthquake:
            for member in self._member:
                res.append("{0} received, need to run away !!!".format(member))
        elif event == Event.Joke:
            for member in self._member:
                res.append("{0} received, A false alarm ...".format(member))


# decorate
class LivingRoom(SomeWhere):
    pass


# decorate
class StudyRoom(SomeWhere):
    pass


class School(SomeWhere):
    pass


class EmergencyAlart(Notifier):
    pass


class Kitchen(Notifier):
    pass


res = []


class TestObserver(unittest.TestCase):
    def test_observer(self):
        global res
        study_room = Observer(StudyRoom())
        living_room = Observer(LivingRoom())
        school = Observer(School())
        emergency_alart = EmergencyAlart()
        kitchen = Kitchen()

        study_room.attach_notifier(emergency_alart)
        living_room.attach_notifier(emergency_alart)
        school.attach_notifier(emergency_alart)
        study_room.attach_notifier(kitchen)
        living_room.attach_notifier(kitchen)

        # My sister is studying in studyroom
        study_room.add_member("My sister")
        # and I am watching TV in living room
        living_room.add_member("I")

        # Just cooking.
        res = []
        kitchen.notify(Event.Joke)
        self.assertListEqual(
            sorted(res),
            sorted(
                [
                    "I received, A false alarm ...",
                    "My sister received, A false alarm ...",
                ]
            ),
        )

        # My sister is on her way to school.
        study_room.remove_member("My sister")
        school.add_member("My sister")
        res = []
        kitchen.notify(Event.Joke)
        self.assertListEqual(sorted(res), sorted(["I received, A false alarm ..."]))

        # Living room alert is no longer needed.
        living_room.detach_notifier(kitchen)
        res = []
        kitchen.notify(Event.Joke)
        self.assertListEqual(sorted(res), sorted([]))

        # I am studying
        living_room.remove_member("I")
        study_room.add_member("I")
        res = []
        kitchen.notify(Event.Joke)
        self.assertListEqual(sorted(res), sorted(["I received, A false alarm ..."]))

        # emergency alart notify you everywhere
        res = []
        emergency_alart.notify(Event.Earthquake)
        self.assertListEqual(
            sorted(res),
            sorted(
                [
                    "I received, need to run away !!!",
                    "My sister received, need to run away !!!",
                ]
            ),
        )
