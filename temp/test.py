def check_overlap(self, area, obj_type):
        '''
        checks if ano object (obj_type) is in the area
        area is given as = ((upperLeft_x, upperLeft_y), 
                            (lowerRight_x, lowerRight_y))
        '''
        



    def generate_house(self, house_size):
        '''
        the function builds houses
        house_size is a tuple (height, width) of the house
        houses are generated at any random valid position
        '''
        upperLeft_x = None
        upperLeft_y = None

        for it in range(100):
            upperLeft_x = np.random.randint(height, size=1)
            upperLeft_y = np.random.randint(width, size=1)

            lowerRight_x = upperLeft_x + house_size[0]
            lowerRight_y = upperLeft_y + house_size[1]
            
            if graph_valid((lowerRight_x, lowerRight_y)) and check_overlap(((upperLeft_x, upperLeft_y), (lowerRight_x, lowerRight_y)), 'box') == False:
                break

        if upper_left_x == None:
            print('No suitable place found for a house!')
            return

        for it in range()