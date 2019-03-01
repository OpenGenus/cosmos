classdef simulator < handle
    % A small simulation of a variation of McCallum's grid-world.
    % Initialized in a random state. The world is only partially
    % observable.
    %
    % reset()        -- reset the world to a random starting state
    % observe()      -- get the observation of the current goal state
    % take_action(a) -- execute action a, returns the reward associated
    %                   with taking this action in the current state
    % isGoal(a)      -- check if in the goal state
    %
    % (c) 2016 Sebastian Wallkoetter
    
    properties(Access=private)
        s = randi(11); % current state
        T = ones(4,11); % transition matrix
        observations = ones(11,1);
        reward_function
    end
    
    methods
        function obj = simulator(~)
            % construct a POMDP based on McCallum's grid world. This
            % routine creates the world by setting the transition function
            % T as well as the observations for each state.
            
            obj.T = [
                4 2   6   7   9   11  7   8   9   10  11
                1 2   3   4   5   6   8   9   10  11  11
                1 2   3   1   2   4   4   8   5   10  11
                1 2   3   4   5   6   7   7   8   9   10
                ];
            obj.observations = [14 14 14 10 10 10 9 5 1 5 3];
        end
        
        function r =  take_action(this, a)
            % execute action a. This will result in a new current state and
            % a reward
            % Input:    a   --- The action to be executed
            % Output:   r   --- The reward obtained from taking action a in
            %                   state s
            
            r = this.reward(a);
            this.s = this.T(a,this.s);
        end
        
        function o = observe(this)
            % Resturns what can be seen in the current state
            % Output:   o   --- The current observation
            
            o = this.observations(this.s);
        end
        
        function reset(this)
            % Reset the world, placing the agent in a random state ~= 2
            
            possible_states = 1:11;
            possible_states(2) = [];
            this.s = randsample(possible_states,1);
        end
        
        function b = isGoal(this)
            % returns true if the current state is the goal state
            % Output:   b   --- True, if goal has been reached. False
            %                   otherwise.
            
            b = (this.s == 2);
        end
        
    end
    
    methods(Access = private)
        function r = reward(this, a)
            % the reward for taking action a in the current state
            % Input:    a   --- the action taken
            % Output:   r   --- reward for taking that action in the
            %                   current state
            
            if this.s == 5 && a == 3
                r = 10;
            else
                r = 0;
            end
        end
    end
ends