interface Component {
    operation(): string;
}

interface HelloWorldDecorator {
    operation(): string;
}

class ComponentImpl implements Component {
    public operation(): string {
        return 'This method is decorated';
    }
}

// This is the general way to implement decorators
class HelloWorldDecoratorImpl implements HelloWorldDecorator {
    private _component: Component;

    constructor(component: Component) {
        this._component = component;
    }

    public operation(): string {
        return `Hello world! ${this._component.operation()}`;
    }
}

let testComponent = new ComponentImpl();
let decoratedTestComponent = new HelloWorldDecoratorImpl(testComponent);
console.log(decoratedTestComponent.operation());

// Here we use TypeScript's built in support for decorators
// What we are using here are class decorators.
// There are also: class property, class method, class accessor
// and class method parameter decorators
@helloWorldClassDecorator
class ComponentAltImpl implements Component {
    public operation(): string {
        return 'This message will be overriden';
    }
}

function helloWorldClassDecorator<T extends { new (...args: any[]): {} }>(constructor: T) {
    return class extends constructor implements HelloWorldDecorator {
        operation() {
            return `Hello world again! ${constructor.prototype.operation()}`;
        }
    };
}

let syntacticSugarDecorator = new ComponentAltImpl();
console.log(syntacticSugarDecorator.operation());
