classdef nsm_agent < handle
    % The agent keeps a history of all past episodes (max. 20 steps).
    % This information is used to make decisions about the current action,
    % by comparing chains of previous observations and actions.
    
    properties(Access=private)
        episodes_stored = 0;
        world = simulator();
        STM = zeros(20,3);
        LTM = zeros(20,3,0);
    end
    
    methods
        function [steps, ret_LTM] =  Trials(this, num_trials)
            % gather num_trials many episodes using NSM action
            % selection. For each Episode reccord the total number of steps
            % and the last 20 visited nodes.
            % Input:    num_trials  --- the number of trials to be run
            % Output:   steps       --- 1D array where steps(idx) corresponds to
            %                           the number of steps needed to reach the
            %                           goal in episode idx.
            %           LTM         --- A reccord of the last 20 reccorded
            %                           observations, actions and rewards.
            %                           LTM(20,:) is the last observed state.
            %                           If an episode requires less than 20
            %                           steps, the top rows are zero padded
            %                           until size(LTM) = [20 3];
            
            this.LTM = zeros(20,3,num_trials);
            
            steps = zeros(1,num_trials);
            for idx = 1:num_trials
                [step, foo] = this.NSMEpisode();
                steps(idx) = step;
                this.LTM(:,:,idx) = foo;
                this.episodes_stored = this.episodes_stored + 1;
            end
            ret_LTM = this.LTM;
        end

    end
    methods(Access = private)
        function [num_steps, ret_mat] = NSMEpisode(this)
            % Generates an episode using previously observed experience
            % stored in LTM.
            % Output:   num_steps   --- The total number of steps until the
            %                           goal was reached.
            %           ret_mat     --- The last 20 observations, actions
            %                           and rewards, stored in LTM format.
            gamma = 0.9;
            num_steps = 0;
            
            % make sure the world is in a random state and we have no
            % current memory
            this.world.reset();
            this.STM = zeros(20,3);
            
            % traverse the world and try to pick a good action in each step
            while ~this.world.isGoal()
                o = this.world.observe();
                a = this.NSMSelectAction(o);
                r = this.world.take_action(a);
                
                % after each step, reccord what happned
                this.STM = circshift(this.STM,[-1 0]);
                this.STM(20,:) = [o a r];
                num_steps = num_steps + 1;
            end
            
            % calculate the discounted reward
            this.STM(:,3) = this.STM(20,3) * gamma.^(19:-1:0);
            this.STM(1:(20-num_steps),3) = 0;
            
           ret_mat = this.STM;
        end
        
        function a = NSMSelectAction(this, o)
            % Select an action based on actions and observations 
            % (STM) made in this episode and past experiences (LTM).
            % The action selection is epsilon-greedy, with epsilon = 10 %.
            % Input:    o   --- the current observation
            % Output:   a   --- action chosen
            
            if rand < 0.1
                % pick a random action
                a = randi(4);
                
            else
                % select an action based on past experiences
                
                % find the 10 closest POMDP states observed in the past and
                % average their discounted reward with respect to the first
                % action taken.
                kNN = this.kNearest(o);
                rewards = zeros(1,4);
                for idx = 1:4
                    same_action = (kNN(:,2) == idx);
                    rewards(idx) = mean(kNN(same_action,3));
                end
                rewards(isnan(rewards)) = 0;
                
                % select the best action. If tie for multiple, pick random
                % witin those.
                max_val = max(rewards);
                available_actions = 1:4;
                available_actions = ...
                    (available_actions(abs(rewards-max_val) < 0.01));
                rand_action = mod(randi(12),size(available_actions,1)) + 1;
                a = available_actions(rand_action);
            end
        end
        
        function score = proximity(this, episode, step, o)
            % Calculate how close a state in the LTM is to the current
            % state.
            % Input:    (episode,step)  --- The state in the LTM
            %           o               --- The current observation
            % Output:   score           --- The closeness of the two
            %                               states. Higher is closer.     
            
            % if observation differs from LTM's present observation,
            % score is 0
            if this.LTM(step,1,episode) ~= o
                score = 0;
                return;
            end
            
            % local copy of LTM stripped from everything unneeded
            past = this.LTM(1:step-1,1:2,episode);
            zero_rows = all(past == 0,2);
            past(zero_rows,:) = [];
            
            % local copy of STM stripped from everything unneeded
            local_STM = this.STM(:,1:2);
            zero_rows = all(local_STM == 0,2);
            local_STM(zero_rows,:) = [];
            
            % compare LTM's past to STM past to see how close it is
            STM_size = size(local_STM,1);
            past_size = size(past, 1);
            common = (min(STM_size,past_size)-1):-1:0;
            past = past(end - common,:);
            local_STM = this.STM(end - common,1:2);
            
            %find out how many (o,a) pairs match
            matches = flipud(all(past == local_STM,2));
            num_matches = find([matches; 0] == 0, 1);
            score = 1 + (num_matches-1);
        end
        
        function kNN = kNearest(this, o)
            % find and return the 10 nearest neighbours in the LTM, given 
            % the STM and a current observation
            % Input:    o       --- The current observation
            % Output:   kNN     --- A list of the 10 nearest states and
            %                       their score.
            
            kNN = zeros(10,4);
            lowest_score = 0;
            
            for step = 20:-1:2
                for episode = 1:this.episodes_stored
                    % this entire for loop could be vectorized. But this
                    % would require to refactor and remove proximity() thus
                    % it has been omitted in this implementation.
                    
                    score = this.proximity(episode,step,o);
                    if lowest_score <= score && score > 0
                        [~,idx] = min(kNN(:,4));
                        kNN(idx,:) = [this.LTM(step,:,episode) score];
                        lowest_score = min(kNN(:,4));
                    end
                end
            end
        end
    end
end