# Part of Cosmos by OpenGenus Foundation


class Singleton:
    __instance = None

    @property
    def x(self):
        return self.__x

    @x.setter
    def x(self, value):
        self.__x = value

    @staticmethod
    def instance():
        if not Singleton.__instance:
            Singleton.__instance = Singleton()
        return Singleton.__instance
