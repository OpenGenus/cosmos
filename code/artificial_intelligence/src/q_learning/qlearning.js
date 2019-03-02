// Q Learning Introduction: https://en.wikipedia.org/wiki/Q-learning
// Algorithm: Q(s,a):=Q(s,a)+α[r+γ*maxQ(s′,a′)−Q(s,a)]

const TERMINAL = "terminal";
const TOTAL_EPISODE = 10;

function State(stateName, actions) {
  this.name = stateName;
  // Actions of State
  this.actions = {};
  actions.forEach(action => {
    this.actions[action] = 0;
  });
}

class QLearning {
  constructor(
    actions,
    learningRate = 0.01,
    discountFactor = 0.9,
    eGreedy = 0.9
  ) {
    this.actions = actions;
    this.lr = learningRate;
    this.gamma = discountFactor;
    this.epsilon = eGreedy;
    // Q Table Structure
    this.states = {};
    this.statesList = [];
  }

  addState(name, actions) {
    const state = new State(name, actions);
    this.states[name] = state;
    this.statesList.push(state);
    return state;
  }

  static bestAction(stateActions) {
    return new Promise(resolve => {
      let bestAction = null;
      let bestActionReward = null;
      Object.keys(stateActions).forEach(actionName => {
        if (!bestActionReward) {
          bestActionReward = stateActions[actionName];
        }
        if (stateActions[actionName] > bestActionReward) {
          bestAction = actionName;
          bestActionReward = stateActions[actionName];
        } else if (
          stateActions[actionName] === bestActionReward &&
          Math.random() > 0.5
        ) {
          bestAction = actionName;
        } else {
          bestAction = bestAction || actionName;
        }
      });
      resolve(bestAction);
    });
  }

  checkStateExist(stateName) {
    if (!this.states[stateName]) this.addState(stateName, this.actions);
  }

  async chooseAction(stateName) {
    this.checkStateExist(stateName);

    console.log(`Q Value: ${JSON.stringify(this.states[stateName].actions)}`);

    let nextAction = null;
    if (Math.random() < this.epsilon) {
      // choose next action based on Q Value
      const stateActions = this.states[stateName].actions;
      nextAction = await QLearning.bestAction(stateActions);
      console.log(`pickAction: ${nextAction}`);
    } else {
      // choose next action randomly
      nextAction = this.actions[
        Math.floor(Math.random() * this.actions.length)
      ];
      console.log(`randomAction: ${nextAction}`);
    }
    return nextAction;
  }

  learn(stateName, actionName, reward, nextStateName) {
    this.checkStateExist(nextStateName);

    const qPredict = this.states[stateName].actions[actionName];

    // γ*maxQ(s′,a′)
    const maxQValue =
      this.gamma *
      Math.max(...Object.values(this.states[nextStateName].actions));
    const qTarget = stateName !== TERMINAL ? reward + maxQValue : reward;

    this.states[stateName].actions[actionName] +=
      this.lr * (qTarget - qPredict);
  }
}

//
// SAMPLE Command Line Environment
//

class RoadEnv {
  constructor() {
    this.totalActions = ["LEFT", "RIGHT"];
    this.resetStateName = "0";
  }

  static render(stateName) {
    return new Promise(resolve => {
      const road = ["-", "-", "-", "-", "-", "-"];
      road[Number(stateName)] = "0";
      console.log(`\n ${road.join("")}`);
      resolve();
    });
  }

  static step(stateName, action) {
    return {
      "0-LEFT": {
        nextStateName: TERMINAL,
        reward: -1000,
        done: true
      },
      "0-RIGHT": RoadEnv.normalTransition("1"),
      "1-LEFT": RoadEnv.normalTransition("0"),
      "1-RIGHT": RoadEnv.normalTransition("2"),
      "2-LEFT": RoadEnv.normalTransition("1"),
      "2-RIGHT": RoadEnv.normalTransition("3"),
      "3-LEFT": RoadEnv.normalTransition("2"),
      "3-RIGHT": RoadEnv.normalTransition("4"),
      "4-LEFT": RoadEnv.normalTransition("3"),
      "4-RIGHT": {
        nextStateName: TERMINAL,
        reward: 100,
        done: true
      }
    }[`${stateName}-${action}`];
  }

  static normalTransition(stateName) {
    return {
      nextStateName: stateName,
      reward: 0,
      done: false
    };
  }
}

const update = (RL, stateName, totalSteps) => {
  return new Promise(resolve => {
    setTimeout(async () => {
      RoadEnv.render(stateName);

      console.log(`stateName: ${stateName}`);
      const action = await RL.chooseAction(stateName);

      const step = RoadEnv.step(stateName, action);

      let nextStateName = null;
      let reward = null;
      let done = null;
      ({ nextStateName, reward, done } = step);

      RL.learn(stateName, action, reward, nextStateName);
      const currentSteps = totalSteps + 1;

      if (!done) {
        resolve(await update(RL, nextStateName, currentSteps));
      } else {
        console.log(`endReward: ${reward}`);
        resolve(totalSteps);
      }
    }, 100);
  });
};

// Run Q Learning For 10 Episode
const run = async () => {
  const env = new RoadEnv();
  const RL = new QLearning(env.totalActions);

  for (let episode = 1; episode <= TOTAL_EPISODE; episode += 1) {
    const stateName = env.resetStateName;
    let totalSteps = 1;
    console.log(`\nEpisode: ${episode} =============================== `);
    totalSteps = await update(RL, stateName, totalSteps);
    console.log(`\nTotalSteps: ${totalSteps}`);
  }
};

run();
